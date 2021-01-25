#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool HasBall(vector<string> board, char ball) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == ball) return true;
		}
	}
	return false;
}

vector<string> Rotate(vector<string> board) {
	vector<string> temp(board[0].size(), string(board.size(), '1'));
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			temp[j][board[0].size() - i - 1] = board[i][j];
		}
	}
	board = temp;
	return board;
}

vector<string> MoveLeft(vector<string> board) {
	for (int i = 1; i < board.size()-1; i++) {
		string row = "";
		for (int j = 1; j < board[0].size()-1; j++) {
			if (board[i][j] == '#') {
				for (int k = 0; k < j - row.size() - 1; k++) {
					row.push_back('.');
				}
				row.push_back('#');
			}
			if (board[i][j] == 'O') {
				for (int k = 0; k < j - row.size() - 1; k++) {
					row.push_back('.');
				}
				row.push_back('O');
			}
			if (board[i][j] == 'R' || board[i][j] == 'B') {
				if (!row.empty() && row.back() == 'O')
					continue;
				else
					row.push_back(board[i][j]);
			}
		}
		for (int j = 0; j < board[0].size() - row.size() - 2; j++) {
			row.push_back('.');
		}
		row = '#' + row + '#';
		board[i] = row;
	}
	return board;
}

void DFS(vector<string> board, int &answer, int count) {
	if (!HasBall(board, 'B')) return;
	if (!HasBall(board, 'R')) {
		if (count < answer) {
			answer = count;
			cout << endl;
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					cout << board[i][j];
				}
				cout << endl;
			}
			cout << count << endl;
			cout << endl;
		}
		return;
	}
	if (count == 5) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		DFS(MoveLeft(board), answer, count + 1);
		board = Rotate(board);
	}
}

int main() {
	int answer = 11;
	int n, m;
	vector<string> board;
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string row;
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			row += c;
		}
		board.push_back(row);
	}

	DFS(board, answer, 0);
	if (answer == 11) answer = -1;
	cout << answer;

	return 0;
}