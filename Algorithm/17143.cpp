//#include <iostream>
//#include <vector>
//#include <cstring>
//#define INF 1e9;
//#define abs(x) (x < 0 ? -1 * (x) : x)
//
//using namespace std;
//
//struct Shark {
//	int y;
//	int x;
//	int speed;
//	int dir;
//	int size;
//	Shark(int _y, int _x, int _speed, int _dir, int _size) {
//		y = _y;
//		x = _x;
//		speed = _speed;
//		dir = _dir;
//		size = _size;
//	}
//};
//
//int R, C, M, fisherPos = 0, sumSize = 0;
//int sea[101][101];
//int movedir[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} };
//vector<Shark> sharks;
//
//void GetInput() {
//	cin >> R >> C >> M;
//	for (int i = 0; i < M; i++) {
//		int r, c, s, d, z;
//		cin >> r >> c >> s >> d >> z;
//		sharks.push_back(Shark(r, c, s, (d-1), z));
//		sea[r][c] = (z);
//	}
//}
//
//int GetDistance(int x, int y, int xx, int yy) {
//	return (abs(x - xx) + abs(y - yy));
//}
//
//void CatchNearest() {
//	if (sharks.empty()) return;
//	int shark = -1, minDist = INF;
//	for (int i = 0; i < sharks.size(); i++) {
//		if (sharks[i].x != fisherPos) continue;
//		int dist = GetDistance(fisherPos, 0, sharks[i].x, sharks[i].y);
//		if (dist < minDist) {
//			minDist = dist;
//			shark = i;
//		}
//	}
//	if (shark == -1) return;
//	sea[sharks[shark].y][sharks[shark].x] = 0;
//	sumSize += sharks[shark].size;
//	sharks.erase(sharks.begin() + shark);
//}
//
//void MoveShark() {
//	if (sharks.empty()) return;
//	for (int i = 1; i <= R; i++) {
//		for (int j = 1; j <= C; j++) {
//			sea[i][j] = 0;
//		}
//	}
//	for (int i = 0; i < sharks.size(); i++) {
//		int rot = sharks[i].dir < 2 ? (2 * (R - 1)) : (2 * (C - 1));
//		int dist = sharks[i].speed >= rot ? sharks[i].speed % rot : sharks[i].speed;
//		if (dist == 0 && (sharks[i].speed / rot) % 2 == 1) sharks[i].dir = sharks[i].dir % 2 == 0 ? sharks[i].dir + 1 : sharks[i].dir - 1;
//		for (int j = 0; j < dist; j++) {
//			int nextY = sharks[i].y + movedir[sharks[i].dir][0];
//			int nextX = sharks[i].x + movedir[sharks[i].dir][1];
//			if (nextY > R) {
//				nextY = R - 1;
//				sharks[i].dir = 0;
//			}
//			if (nextY < 1) {
//				nextY = 2;
//				sharks[i].dir = 1;
//			}
//			if (nextX < 1) {
//				nextX = 2;
//				sharks[i].dir = 2;
//			}
//			if (nextX > C) {
//				nextX = C - 1;
//				sharks[i].dir = 3;
//			}
//			sharks[i].y = nextY;
//			sharks[i].x = nextX;
//		}
//		sea[sharks[i].y][sharks[i].x] = sharks[i].size > sea[sharks[i].y][sharks[i].x] ? sharks[i].size : sea[sharks[i].y][sharks[i].x];
//	}
//	for (int i = 0; i < sharks.size(); i++) {
//		if (sharks[i].size < sea[sharks[i].y][sharks[i].x]) {
//			sharks.erase(sharks.begin() + i);
//			i--;
//		}
//	}
//}
//
//void Solve() {
//	while (fisherPos < C) {
//		if (sharks.empty()) break;
//		fisherPos++;
//		CatchNearest();
//		MoveShark();
//	}
//	cout << sumSize;
//}
//
//int main() {
//	GetInput();
//	Solve();
//	return 0;
//}