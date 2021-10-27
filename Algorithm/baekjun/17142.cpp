#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9

using namespace std;

int N, M;
int dir[4][2] = { {0, 1},{0, -1},{1, 0},{-1, 0} };
int minTime = INF;
bool visited[10] = { false, };
vector<vector<int>> lab;
vector<pair<int, int>> viruses;

void GetInput() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			int room;
			cin >> room;
			row.push_back(room);
			if (room == 2) viruses.push_back(make_pair(i, j));
		}
		lab.push_back(row);
	}
}

bool Check(vector<vector<int>> lab) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (lab[i][j] == 0) return false;
		}
	}
	return true;
}

void Spread() {
	int spreadTime = 0;
	vector<vector<int>> lab_cpy = lab;
	bool checked[50][50] = { false, };
	queue<pair<pair<int, int>, int>> q;

	if (Check(lab_cpy)) {
		minTime = 0;
		return;
	}

	for (int i = 0; i < viruses.size(); i++) {
		if (!visited[i]) continue;
		q.push(make_pair(viruses[i], spreadTime));
		checked[viruses[i].first][viruses[i].second] = true;
	}
	while (!q.empty()) {
		int y = q.front().first.first;
		int x = q.front().first.second;
		int time = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (checked[ny][nx]) continue;
			checked[ny][nx] = true;
			if (lab_cpy[ny][nx] == 0 || lab_cpy[ny][nx] == 2) {
				if (lab_cpy[ny][nx] == 0) spreadTime = time + 1 > spreadTime ? time + 1 : spreadTime;
				q.push(make_pair(make_pair(ny, nx), time+1));
				lab_cpy[ny][nx] = 2;
			}
		}
	}
	if (Check(lab_cpy)) minTime = spreadTime < minTime ? spreadTime : minTime;
}

void ChooseVirus(int pos, int cnt) {
	if (cnt == M) {
		Spread();
		return;
	}
	for (int i = pos; i < viruses.size(); i++) {
		if (visited[i]) continue;
		visited[i] = true;
		ChooseVirus(i, cnt + 1);
		visited[i] = false;
	}
}

void Solve() {
	ChooseVirus(0, 0);
	if (minTime == INF) cout << -1;
	else cout << minTime;
}

int main() {
	GetInput();
	Solve();
	return 0;
}