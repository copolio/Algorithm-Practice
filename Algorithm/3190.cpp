//#include <iostream>
//#include <vector>
//#include <map>
//
//using namespace std;
//
//int gamemap[101][101] = { 0, }; // 0 = ºó°ø°£, 1 = »ç°ú, 2 = ¹ì
//
//struct Direction {
//	int value; // 0123 -> ºÏµ¿³²¼­
//	void Rotate() {
//		value++;
//		if (value > 3) value = 0;
//	}
//	void CounterRotate() {
//		value--;
//		if (value < 0) value = 3;
//	}
//};
//
//struct Point {
//	int x;
//	int y;
//	Direction dir;
//	Point() {
//		x = 0;
//		y = 0;
//		dir.value = 1;
//	}
//	Point(const Point& s) {
//		x = s.x;
//		y = s.y;
//		dir.value = s.dir.value;
//	}
//	void Move() {
//		switch (dir.value) {
//		case 0:
//			y--;
//			break;
//		case 1:
//			x++;
//			break;
//		case 2:
//			y++;
//			break;
//		case 3:
//			x--;
//			break;
//		}
//	}
//};
//
//void PrintMap(int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << gamemap[i][j];
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//int main() {
//	int N, K, L;
//	int time = 0;
//	vector<Point> snake (1, Point());
//	map<int, char> snakeDirections;
//	gamemap[0][0] = 2;
//
//	cin >> N >> K;
//	for (int i = 0; i < K; i++) {
//		int col, row;
//		cin >> col >> row;
//		gamemap[col - 1][row - 1] = 1;
//	}
//	cin >> L;
//	for (int i = 0; i < L; i++) {
//		int X;
//		char C;
//		cin >> X >> C;
//		snakeDirections[X] = C;
//	}
//
//	while (true) {
//		//cout << "time : " << time << endl;
//		//PrintMap(N);
//		Point head = snake[0];
//		if (snakeDirections.count(time) > 0) {
//			if (snakeDirections[time] == 'L') {
//				head.dir.CounterRotate();
//			}
//			else if (snakeDirections[time] == 'D') {
//				head.dir.Rotate();
//			}
//		}
//		head.Move();
//		time++;
//		//Á×¾úÀ»¶§;
//		if (head.x < 0 || head.x >= N || head.y < 0 || head.y >= N) {
//			cout << time << endl;
//			break;
//		}
//		if (gamemap[head.y][head.x] == 0) {
//			for (auto point : snake) {
//				gamemap[point.y][point.x] = 0;
//			}
//			snake.insert(snake.begin(), head);
//			snake.pop_back();
//			for (auto point : snake) {
//				gamemap[point.y][point.x] = 2;
//			}
//		}
//		else if (gamemap[head.y][head.x] == 1) {
//			gamemap[head.y][head.x] = 2;
//			snake.insert(snake.begin(), head);
//		}
//		else if (gamemap[head.y][head.x] == 2) {
//			cout << time << endl;
//			break;
//		}
//	}
//
//	return 0;
//}