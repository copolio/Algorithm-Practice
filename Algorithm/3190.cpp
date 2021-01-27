#include <iostream>
#include <vector>

using namespace std;

struct Direction {
	int value; // 0123 -> ºÏµ¿³²¼­
	void ClockRotate() {
		value++;
		if (value > 3) value = 0;
	}
	void CounterRotate() {
		value--;
		if (value < 0) value = 3;
	}
};

struct Point {
	int x;
	int y;
	Direction dir;
	Point() {
		x = 0;
		y = 0;
		dir.value = 0;
	}
};

int main() {
	int N, K, L;
	vector<vector<Point>> snake;
	vector<pair<int, char>> snakeDirections;

	cin >> N >> K;
	vector<vector<int>> map (N, vector<int>(N, 0));		// 0 = ºó°ø°£, 1 = »ç°ú, 2 = ¹ì
	for (int i = 0; i < K; i++) {
		int col, row;
		cin >> col >> row;
		map[row - 1][col - 1] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int X;
		char C;
		cin >> X >> C;
		snakeDirections.push_back(make_pair(X, C));
	}

	return 0;
}