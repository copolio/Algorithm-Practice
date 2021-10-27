#include <iostream>
#define INF 1e9
using namespace std;
int N, diff = INF;
int S[20][20] = { 0, };
bool used[20] = { false, };
void getDifference(int startIdx, int nUsed) {
	if (nUsed == N / 2) {
		int resultStart = 0;
		int resultLink = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (used[i] && used[j]) {
					resultStart += S[i][j];
				}
				else if (!used[i] && !used[j]) {
					resultLink += S[i][j];
				}
			}
		}
		diff = abs(resultStart - resultLink) < diff ? abs(resultStart - resultLink) : diff;
		return;
	}
	for (int i = startIdx; i < N; i++) {
		if (!used[i]) {
			used[i] = true;
			getDifference(i+1, nUsed+1);
			used[i] = false;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
	getDifference(0, 0);
	cout << diff << endl;
	return 0;
}