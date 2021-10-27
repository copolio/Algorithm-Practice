#include <iostream>
#include <algorithm>
#include <vector>

#define INF 1e9

using namespace std;

int N, minDiff = INF;
int A[21][21] = { 0, };

void GetInput() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
}

void SetArea(int y, int x, int d1, int d2) {
	vector<int> population(5, 0);

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			//1�� ���ű�
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				population[0] += A[r][c];
			}
			//2�� ���ű�
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				population[1] += A[r][c];
			}
			//3�� ���ű�
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				population[2] += A[r][c];
			}
			//4�� ���ű�
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				population[3] += A[r][c];
			}
			//5�� ���ű�
			else {
				population[4] += A[r][c];
			}
		}
	}

	sort(population.begin(), population.end());
	int diff =  population[4] - population[0];
	minDiff = diff < minDiff ? diff : minDiff;
}

void SetPoint(int y, int x) {
	for (int d1 = 1; d1 < y; d1++) {
		for (int d2 = 1; d2 <= N - y && x + d1 + d2 <= N; d2++) {
			SetArea(y, x, d1, d2);
		}
	}
}

void Solve() {
	for (int y = 2; y <= N - 1; y++) {
		for (int x = 1; x <= N - 2; x++) {
			SetPoint(y, x);
		}
	}
	cout << minDiff;
}

int main() {
	GetInput();
	Solve();

	return 0;
}