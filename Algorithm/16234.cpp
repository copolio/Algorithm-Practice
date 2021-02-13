#include <iostream>
#include <queue>
#define abs(x) x >= 0 ? x : -(x)
using namespace std;

int n, l, r, answer = 0;
int popMap[50][50] = { 0, };
int opened[50][50] = { false, };
int visited[50][50] = { false, };
int moveDir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
queue<pair<int, int>> q;

void GetInput() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> popMap[i][j];
		}
	}
}

void OpenBorder() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			int diff1 = abs(popMap[i][j] - popMap[i][j + 1]);
			int diff2 = abs(popMap[i][j] - popMap[i + 1][j]);
			if (diff1 >= l && diff1 <= r) {
				opened[i][j] = true;
				opened[i][j + 1] = true;
			}
			if (diff2 >= l && diff2 <= r) {
				opened[i][j] = true;
				opened[i + 1][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << opened[i][j] << " ";
		}
		cout << endl;
	}
}

void BFS(int y, int x) {
	q.push(make_pair(y, x));
	while (!q.empty()) {
		int curY = q.front().first;
		int curX = q.front().second;
		visited[curY][curX] = true;
		q.pop();
		if (curX + 1 < n && !visited[curY][curX + 1] && opened[curY][curX + 1]) {
			q.push(make_pair(curY, curX + 1));
		}
		if (curY + 1 < n && !visited[curY + 1][curX] && opened[curY + 1][curX]) {
			q.push(make_pair(curY + 1, curX));
		}
	}
}

void MovePop() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (opened[i][j] && !visited[i][j]) {
				BFS(i, j);
				answer++;
			}
		}
	}
}

int main() {
	GetInput();
	OpenBorder();
	MovePop();
	cout << answer;
	return 0;
}