//#include <iostream>
//#include <vector>
//#include <queue>
//#define abs(x) x > 0 ? x : -1*(x)
//#define INF 1e9
//
//using namespace std;
//
//struct Fish {
//	int x;
//	int y;
//	int size;
//	Fish() {};
//	Fish(int _curY, int _curX, int _curSize) {
//		y = _curY;
//		x = _curX;
//		size = _curSize;
//	}
//};
//
//struct Shark : public Fish {
//	int stomach;
//	Shark() {};
//	Shark(int _curY, int _curX) {
//		y = _curY;
//		x = _curX;
//		size = 2;
//		stomach = 0;
//	}
//	void Eat() {
//		stomach++;
//		if (stomach == size) {
//			size += 1;
//			stomach = 0;
//		}
//	}
//};
//
//int N, curTime = 0;
//int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
//int sea[20][20] = { 0, };
//Shark shark;
//vector<Fish> fishes;
//
//void GetInput() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> sea[i][j];
//			if (sea[i][j] == 9) {
//				shark = Shark(i, j);
//			}
//			else if (sea[i][j] != 0) {
//				fishes.push_back(Fish(i, j, sea[i][j]));
//			}
//		}
//	}
//}
//
//int GetDistance(Fish fish) {
//	queue<vector<int>> q;
//	q.push({ shark.y, shark.x, 0 });
//	bool visited[20][20] = { false, };
//	visited[shark.y][shark.x] = true;
//	while (!q.empty()) {
//		int y = q.front()[0];
//		int x = q.front()[1];
//		int dist = q.front()[2];
//		q.pop();
//		for (int i = 0; i < 4; i++) {
//			int nextY = y + dir[i][0];
//			int nextX = x + dir[i][1];
//			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
//			if (sea[nextY][nextX] > shark.size || visited[nextY][nextX]) continue;
//			if (nextY == fish.y && nextX == fish.x) return dist + 1;
//			visited[nextY][nextX] = true;
//			q.push({ nextY , nextX, dist + 1 });
//		}
//	}
//	return INF;
//}
//
//void Solve() {
//	while (!fishes.empty()) {
//		int nearestFish, minDist = INF;
//		bool canEat = false;
//		for (int i = 0; i < fishes.size(); i++) {
//			if (fishes[i].size >= shark.size) continue;
//			int dist = GetDistance(fishes[i]);
//			if (dist == INF) continue;
//			canEat = true;
//			if (dist < minDist) {
//				minDist = dist;
//				nearestFish = i;
//			}
//			else if (dist == minDist) {
//				if (fishes[nearestFish].y > fishes[i].y) nearestFish = i;
//				else if (fishes[nearestFish].y == fishes[i].y && fishes[nearestFish].x > fishes[i].x) nearestFish = i;
//			}
//		}
//		if (!canEat) break;
//		sea[shark.y][shark.x] = 0;
//		shark.y = fishes[nearestFish].y;
//		shark.x = fishes[nearestFish].x;
//		sea[shark.y][shark.x] = 9;
//		shark.Eat();
//		fishes.erase(fishes.begin() + nearestFish);
//		curTime += minDist;
//		//디버깅용
//		//cout << "좌표: " << shark.y << " " << shark.x << " 크기: " << shark.size << " 이동거리 : " << curTime << endl;
//	}
//	cout << curTime;
//}
//
//int main() {
//	GetInput();
//	Solve();
//	return 0;
//}