#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> finalboard;

int Max(vector<vector<int>> board) {
	int result = 0;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board.size(); j++) {
			if (board[i][j] >= result) result = board[i][j];
		}
	}
	return result;
}

vector<vector<int>> rotate(vector<vector<int>> board) {
	vector<vector<int>> temp(board.size(), vector<int>(board.size()));

	for (int i = 0; i < board.size(); i++) {
		for (int j = board.size() - 1; j >= 0; j--) {
			temp[i][board.size() - j - 1] = board[j][i];
		}
	}
	board = temp;
	return board;
}

vector<vector<int>> MoveUp(vector<vector<int>> board) {
	for (int i = 0; i < board.size(); i++) {
		vector<int> v;
		bool used = false;

		for (int j = 0; j < board.size(); j++) {
			if (board[j][i] == 0)
				continue;

			if (v.size() == 0)
				v.push_back(board[j][i]);
			else {
				if (used == false && v.back() == board[j][i]) {
					v.back() *= 2;
					used = true;
				}
				else {
					v.push_back(board[j][i]);
					used = false;
				}
			}
		}

		for (int j = 0; j < v.size(); j++) {
			board[j][i] = v[j];
		}
		for (int j = v.size(); j < board.size(); j++) {
			board[j][i] = 0;
		}
	}
	return board;
}

vector<vector<int>> ChangeDirection(vector<vector<int>> board, int dir) {
	switch (dir) {
	case 0:
		return MoveUp(board);
		break;
	case 1:
		return MoveUp(rotate(board));
		break;
	case 2:
		return MoveUp(rotate(rotate(board)));
		break;
	case 3:
		return MoveUp(rotate(rotate(rotate(board))));
		break;
	}
}

void DFS(vector<vector<int>> board, int count, int &answer) {
	if (count == 5) {
		if (Max(board) > answer) {
			answer = Max(board);
			finalboard = board;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		DFS(ChangeDirection(board, i), count+1, answer);
	}
}

int main() {
	int answer = 0;
	int size;
	vector<vector<int>> board;

	cin >> size;
	for (int i = 0; i < size; i++) {
		vector<int> row;
		for (int j = 0; j < size; j++) {
			int num;
			cin >> num;
			row.push_back(num);
		}
		board.push_back(row);
	}

	DFS(board, 0, answer);
	cout << answer << endl;

	//for (int i = 0; i < board.size(); i++) {
	//	for (int j = 0; j < board.size(); j++) {
	//		cout << finalboard[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	return 0;
}