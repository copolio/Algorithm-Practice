#include <iostream>
using namespace std;
int N, L;
int roadmap[200][100] = { 0, };
int main() {
	int nRoad = 0;
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> roadmap[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			roadmap[i + N][j] = roadmap[j][i];
		}
	}
	for (int i = 0; i < N * 2; i++) {
		int curPos = 1;
		for (int j = 0; j <= N - 1; j++) {
			if (j == N - 1 && curPos >= 0) nRoad++;
			if (roadmap[i][j] == roadmap[i][j + 1]) curPos++;
			else if (roadmap[i][j] + 1 == roadmap[i][j + 1] && curPos >= L) curPos = 1;
			else if (roadmap[i][j] - 1 == roadmap[i][j + 1] && curPos >= 0) curPos = -L + 1;
			else break;
		}
	}
	cout << nRoad;
	return 0;
}