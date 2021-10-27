#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int H, W, N, maxResource = 0;
int maxSum = 0, maxSpot;
int moveDir[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };

vector<vector<int>> mars;
vector<vector<bool>> visited;

struct Point {
	int x, y, value;
	Point(int _x, int _y, int _value) {
		x = _x;
		y = _y;
		value = _value;
	}
	bool operator< (const Point& c) const {
		if (value != c.value)
			return value < c.value;
		if (y != c.y)
			return y < c.y;
		return x < c.x;
	}
};

set<set<Point>> dp;

void DFS(set<Point> points, int sum) {
	if (maxResource == maxSum) return;
	if (dp.find(points) != dp.end()) return;
	dp.insert(points);
	if (points.size() == N) {
		maxResource = maxResource < sum ? sum : maxResource;
		return;
	}
	priority_queue<Point> pq;
	vector<Point> candidates;
	for (auto point : points) {
		int x = point.x;
		int y = point.y;
		for (int j = 0; j < 4; j++) {
			int nX = x + moveDir[j][0];
			int nY = y + moveDir[j][1];
			if (nX < 0 || nX >= W || nY < 0 || nY >= H) continue;
			if (visited[nY][nX]) continue;
			pq.push(Point(nX, nY, mars[nY][nX]));
		}
	}
	if (points.size() > 1 && !pq.empty()) {
		Point big = pq.top();
		pq.pop();
		visited[big.y][big.x] = true;
		points.insert(big);
		DFS(points, sum + mars[big.y][big.x]);
		visited[big.y][big.x] = false;
		points.erase(Point(big.x, big.y, mars[big.y][big.x]));
	}
	else {
		while (!pq.empty()) {
			Point big = pq.top();
			pq.pop();
			visited[big.y][big.x] = true;
			points.insert(big);
			DFS(points, sum + mars[big.y][big.x]);
			visited[big.y][big.x] = false;
			points.erase(Point(big.x, big.y, mars[big.y][big.x]));
		}
	}
}

void Solve() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (mars[i][j] < maxSpot) continue;
			visited[i][j] = true;
			DFS({ Point(j, i, mars[i][j]) }, mars[i][j]);
		}
	}
	cout << maxResource << endl;
}

void GetInput() {
	cin >> H >> W >> N;
	mars = vector<vector<int>>(H, vector<int>(W, 0));
	visited = vector<vector<bool>>(H, vector<bool>(W, false));
	priority_queue<int> pq;
	for (int i = 0; i < H; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < W; j++) {
			mars[i][j] = row[j] - '0';
			pq.push(row[j] - '0');
		}
	}

	maxSpot = pq.top();
	for (int i = 0; i < N; i++) {
		maxSum += pq.top();
		pq.pop();
	}
}


int main() {
	GetInput();
	Solve();
	return 0;
}