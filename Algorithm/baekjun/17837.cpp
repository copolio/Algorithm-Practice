#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Horse {
	int row;
	int col;
	int dir;
};

int N, K;
int chessBoard[13][13] = { 0, };
int dir[4][2] = { {0,1},{0,-1},{-1, 0},{1, 0} };
vector<int> map[13][13];
vector<Horse> vHorse;

void GetInput() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> chessBoard[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int horseRow, horseCol, horseDir;
		cin >> horseRow >> horseCol >> horseDir;
		Horse horse;
		horse.row = horseRow;
		horse.col = horseCol;
		horse.dir = horseDir - 1;
		vHorse.push_back(horse);
		map[horseRow][horseCol].push_back(i);
	}
}

bool CanStop() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j].size() >= 4) {
				return true;
			}
		}
	}
	return false;
}

void MoveHorse() {
	for (int i = 0; i < K; i++) {
		if (CanStop()) return;
		int nR = vHorse[i].row + dir[vHorse[i].dir][0];
		int nC = vHorse[i].col + dir[vHorse[i].dir][1];
		int nDir = vHorse[i].dir;

		//���� ĭ�� ������ ����ų� �Ķ����� ��� ���� ����
		if (nR < 1 || nR > N || nC < 1 || nC > N || chessBoard[nR][nC] == 2) {
			nDir = (nDir % 2 == 0) ? nDir + 1 : nDir - 1;
			nR = vHorse[i].row + dir[nDir][0];
			nC = vHorse[i].col + dir[nDir][1];
			vHorse[i].dir = nDir;
			if (nR < 1 || nR > N || nC < 1 || nC > N || chessBoard[nR][nC] == 2) continue;
		}

		//�̵��� �� ����
		vector<int> horsesToMove;
		for (int j = 0; j < map[vHorse[i].row][vHorse[i].col].size(); j++) {
			if (map[vHorse[i].row][vHorse[i].col][j] == i) {
				for (int k = j; k < map[vHorse[i].row][vHorse[i].col].size(); k++) {
					horsesToMove.push_back(map[vHorse[i].row][vHorse[i].col][k]);
				}
				map[vHorse[i].row][vHorse[i].col].erase(map[vHorse[i].row][vHorse[i].col].begin() + j, map[vHorse[i].row][vHorse[i].col].end());
				break;
			}
		}

		//�������� ���
		if (chessBoard[nR][nC] == 1) {
			reverse(horsesToMove.begin(), horsesToMove.end());
		}

		//�̵�
		for (int j = 0; j < horsesToMove.size(); j++) {
			int idx = horsesToMove[j];
			vHorse[idx].row = nR;
			vHorse[idx].col = nC;
			map[nR][nC].push_back(idx);
		}
	}
}

void Solve() {
	int curTurn = 0;
	while (true) {
		if (CanStop()) {
			cout << curTurn;
			break;
		}
		if (curTurn > 1000) {
			cout << "-1";
			break;
		}
		MoveHorse();
		curTurn++;
	}
}

int main() {
	GetInput();
	Solve();
	return 0;
}