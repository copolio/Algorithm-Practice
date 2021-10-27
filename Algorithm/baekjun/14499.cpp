#include <iostream>
#include <vector>
using namespace std;

int dice[6] = { 0, };

void Print(vector<vector<int>> &map, int x, int y) {
	if (map[y][x] == 0) {
		map[y][x] = dice[5];
	}
	else {
		dice[5] = map[y][x];
		map[y][x] = 0;
	}
	cout << dice[0] << endl;
}

int main() {
	int N, M, x, y, K;
	cin >> N >> M >> y >> x >> K;
	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<int> commands;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
	for (int i = 0; i < K; i++) {
		int command;
		cin >> command;
		commands.push_back(command);
	}
	for (auto comm : commands) {
		switch (comm) {
		case 1:
			if (x < M - 1) {
				x++;
				int temp = dice[0];
				dice[0] = dice[4];
				dice[4] = dice[5];
				dice[5] = dice[2];
				dice[2] = temp;
				Print(map, x, y);
			}
			break;
		case 2:
			if (x > 0) {
				x--;
				int temp = dice[0];
				dice[0] = dice[2];
				dice[2] = dice[5];
				dice[5] = dice[4];
				dice[4] = temp;
				Print(map, x, y);
			}
			break;
		case 3:
			if (y > 0) {
				y--;
				int temp = dice[0];
				dice[0] = dice[1];
				dice[1] = dice[5];
				dice[5] = dice[3];
				dice[3] = temp;
				Print(map, x, y);
			}
			break;
		case 4:
			if (y < N - 1) {
				y++;
				int temp = dice[0];
				dice[0] = dice[3];
				dice[3] = dice[5];
				dice[5] = dice[1];
				dice[1] = temp;
				Print(map, x, y);
			}
			break;
		}
	}
	return 0;
}