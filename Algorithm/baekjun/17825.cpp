#include <iostream>
#include <vector>
#define START 0
#define END 21

using namespace std;

struct Node {
	int value;
	vector<int> nextNodes;
};

struct Horse {
	int pos;
	Horse() {
		pos = 0;
	}
};

int maxScore = 0;
int dice[10];
Horse horse[4];
vector<Node> board(33);

void InitMap() {
	board[START].value = 0;
	board[END].value = 0;
	for (int i = 0; i <= 20; i++) {
		board[i].value = i * 2;
		board[i].nextNodes.push_back(i + 1);
	}
	board[5].nextNodes.push_back(22);
	for (int i = 22; i <= 24; i++) {
		board[i].value = 13 + 3 * (i - 22);
		board[i].nextNodes.push_back(i + 1);
	}
	board[25].value = 25;
	board[25].nextNodes.push_back(31);
	for (int i = 26; i <= 28; i++) {
		board[i].value = i;
		board[i].nextNodes.push_back(i - 1);
	}
	board[15].nextNodes.push_back(28);
	for (int i = 29; i <= 30; i++) {
		board[i].value = 22 + 2 * (i - 29);
	}
	board[10].nextNodes.push_back(29);
	board[29].nextNodes.push_back(30);
	board[30].nextNodes.push_back(25);
	board[31].value = 30;
	board[31].nextNodes.push_back(32);
	board[32].value = 35;
	board[32].nextNodes.push_back(20);
}

bool CanMove(Horse horse, int moveDist) {
	if (horse.pos == END) return false;
	if (board[horse.pos].nextNodes.size() == 1) {
		while (moveDist > 0) {
			if (horse.pos == END) return true;
			horse.pos = board[horse.pos].nextNodes[0];
			moveDist--;
		}
	}
}

void DFS(int idx, int score) {
	if (idx == 10) {
		maxScore = maxScore < score ? score : maxScore;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int moveDist = dice[idx];
		Horse curHorse = horse[i];
		if (curHorse.pos == END) continue;
		if (board[curHorse.pos].nextNodes.size() == 1) {
			while (moveDist > 0) {
				if (curHorse.pos == END) break;
				curHorse.pos = board[curHorse.pos].nextNodes[0];
				moveDist--;
			}
		}
		else {
			curHorse.pos = board[curHorse.pos].nextNodes[1];
			moveDist--;
			while (moveDist > 0) {
				if (curHorse.pos == END) break;
				curHorse.pos = board[curHorse.pos].nextNodes[0];
				moveDist--;
			}
		}
		bool canMove = true;
		for (int j = 0; j < 4; j++) {
			if (i == j) continue;
			if (horse[j].pos == curHorse.pos && horse[j].pos != END) {
				canMove = false;
				break;
			}
		}
		if (canMove) {
			int temp = horse[i].pos;
			horse[i].pos = curHorse.pos;
			DFS(idx + 1, score + board[horse[i].pos].value);
			horse[i].pos = temp;
		}
	}
}

int main() {
	InitMap();
	for (int i = 0; i < 10; i++) {
		cin >> dice[i];
	}
	DFS(0, 0);
	cout << maxScore;
	return 0;
}