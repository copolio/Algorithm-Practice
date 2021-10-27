#include <iostream>
#include <vector>
#define INF 1e9
#define ABS(x) x > 0 ? x : -x

using namespace std;

int N, M, answer = INF;
int cityMap[51][51];
bool visited[2500] = { false, };
vector<pair<int, int>> houses;
vector<pair<int, int>> chickenShops;

void GetDistance() {
	int sum = 0;
	for (int i = 0; i < houses.size(); i++) {
		int dist = INF;
		for (int j = 0; j < chickenShops.size(); j++) {
			if (visited[j]) {
				dist = dist > abs(houses[i].first - chickenShops[j].first) + abs(houses[i].second - chickenShops[j].second) ? 
					abs(houses[i].first - chickenShops[j].first) + abs(houses[i].second - chickenShops[j].second) : dist;
			}
		}
		sum += dist;
	}
	answer = answer > sum ? sum : answer;
}

void DFS(int cnt, int pos) {
	if (cnt >= M) {
		GetDistance();
		return;
	}
	for (int i = pos; i < chickenShops.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			DFS(cnt + 1, i);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> cityMap[i][j];
			if (cityMap[i][j] == 1) houses.push_back(make_pair(i, j));
			else if (cityMap[i][j] == 2) chickenShops.push_back(make_pair(i, j));
		}
	}
	DFS(0, 0);
	cout << answer;

	return 0;
}