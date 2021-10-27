#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, answer = 0, curYear = 0;
int nutrition[11][11];
int a[11][11];
int movedir[8][2] = { {-1,-1},{-1,0},{-1,+1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };
vector<int> tree[11][11];

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
		tree[y][x].push_back(z);
	}
}

void SpringAndSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].empty()) continue;
			sort(tree[i][j].begin(), tree[i][j].end());
			int sumNutrition = 0;
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				//�� ���缷��
				if (nutrition[i][j] + sumNutrition >= age) {
					sumNutrition -= age;
					tree[i][j][k] += 1;
				}
				//���� ��û�� & ��� �߰�
				else {
					for (int l = k; l < tree[i][j].size(); l++) {
						age = tree[i][j][l];
						sumNutrition += age / 2;
					}
					tree[i][j].erase(tree[i][j].begin() + k, tree[i][j].end());
				}
			}
			nutrition[i][j] += sumNutrition;
		}
	}
}

void FallAndWinter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//�ܿ�
			nutrition[i][j] += a[i][j];
			if (tree[i][j].empty()) continue;
			//����
			for (int k = 0; k < tree[i][j].size(); k++) {
				int age = tree[i][j][k];
				//����
				if (age > 0 && age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int r = i + movedir[k][0];
						int c = j + movedir[k][1];
						if (r < 1 || r > N || c < 1 || c > N) continue;
						tree[r][c].push_back(1);
					}
				}
			}
		}
	}
}

void Simulate() {
	for (; curYear < K; curYear++) {
		SpringAndSummer();
		FallAndWinter();
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