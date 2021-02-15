#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

int N, M, K, answer = 0;
int nutrition[11][11];
int a[11][11];
int movedir[8][2] = { {-1,-1},{-1,0},{-1,+1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
priority_queue<int, vector<int>, greater<int>> tree[11][11];

void GetInput() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
			nutrition[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		int x, y, z;
		vector<int> temp;
		cin >> y >> x >> z;
		tree[y][x].push(z);
	}
}

void SpringSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			priority_queue<int, vector<int>, greater<int>> tempq;
			while (!tree[i][j].empty()) {
				int age = tree[i][j].top();
				tree[i][j].pop();
				//영양섭취
				if (nutrition[i][j] >= age) {
					nutrition[i][j] -= age;
					tempq.push(age + 1);
				}
				//즉시사망 & 양분 추가
				else {
					nutrition[i][j] += age / 2;
					while (!tree[i][j].empty()) {
						age = tree[i][j].top();
						tree[i][j].pop();
						nutrition[i][j] += age / 2;
					}
				}
			}
			tree[i][j] = tempq;
		}
	}
}

void Fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].empty()) continue;
			priority_queue<int, vector<int>, greater<int>> tempq;
			while (!tree[i][j].empty()) {
				int age = tree[i][j].top();
				tree[i][j].pop();
				//번식
				if (age > 0 && age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int r = i + movedir[k][0];
						int c = j + movedir[k][1];
						if (r < 1 || r > N || c < 1 || c > N) continue;
						tree[r][c].push(1);
					}
				}
				tempq.push(age);
			}
			tree[i][j] = tempq;
		}
	}
}

void Winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			nutrition[i][j] += a[i][j];
		}
	}
}

void Simulate() {
	for (int i = 0; i < K; i++) {
		SpringSummer();
		Fall();
		Winter();
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += tree[i][j].size();
		}
	}
	cout << answer;
}

int main() {
	GetInput();
	Simulate();
	return 0;
}