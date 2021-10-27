#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int N, M, H, answer = INF;
bool ladder[271][11] = { false, };

bool CanBuild(int y, int x) {
	if (ladder[y][x]) return false;
	if (ladder[y][x - 1]) return false;
	if (ladder[y][x + 1]) return false;
	return true;
}

bool CanMoveDown() {
	for (int i = 1; i <= N; i++) {
		int curPos = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][curPos]) {
				curPos++;
			}
			else if (ladder[j][curPos - 1]) {
				curPos--;
			}
		}
		if (curPos != i) return false;
	}
	return true;
}

void DFS(int cnt, int curY) {
	if (cnt > 3) return;
	if (CanMoveDown()) {
		answer = cnt < answer ? cnt : answer;
		return;
	}
	for (int i = curY; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (CanBuild(i, j)) {
				ladder[i][j] = true;
				DFS(cnt + 1, i);
				ladder[i][j] = false;
			}
		}
	}
}

int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> y >> x;
		ladder[y][x] = true;
	}
	DFS(0, 1);
	answer = answer > 3 ? -1 : answer;
	cout << answer;
	return 0;
}