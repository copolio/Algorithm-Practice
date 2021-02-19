//#include <iostream>
//#include <vector>
//#include <numeric>
//
//using namespace std;
//
//int R, C, T;
//int room[50][50] = { 0, };
//int dir[4][2] = { { -1, 0 } , { 0, 1 }, { 1, 0 }, { 0, -1 }};
//vector<int> dusts[50][50];
//vector<pair<int, int>> filters;
//
//void GetInput() {
//	cin >> R >> C >> T;
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> room[i][j];
//			if (room[i][j] == -1) filters.push_back(make_pair(i, j));
//		}
//	}
//}
//
//void SpreadDust() {
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (room[i][j] < 1) continue;
//			int spread = 0;
//			for (int k = 0; k < 4; k++) {
//				int nY = i + dir[k][0];
//				int nX = j + dir[k][1];
//				if (nY < 0 || nY >= R || nX < 0 || nX >= C) continue;
//				if (room[nY][nX] == -1) continue;
//				dusts[nY][nX].push_back(room[i][j]/5);
//				spread += room[i][j] / 5;
//			}
//			room[i][j] -= spread;
//		}
//	}
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (dusts[i][j].empty()) continue;
//			int sum = accumulate(dusts[i][j].begin(), dusts[i][j].end(), 0);
//			dusts[i][j].clear();
//			room[i][j] += sum;
//		}
//	}
//}
//
//void FilterUp() {
//	int cY = filters[0].first;
//	int cX = filters[0].second;
//	int cDir = 0;
//	while (true) {
//		int nY = cY + dir[cDir][0];
//		int nX = cX + dir[cDir][1];
//		if (nY == filters[0].first && nX == filters[0].second) break;
//		if (nY < 0 || nY > filters[0].first || nX < 0 || nX >= C)
//			cDir = (cDir + 1) % 4;
//		nY = cY + dir[cDir][0];
//		nX = cX + dir[cDir][1];
//		if (cY != filters[0].first || cX != filters[0].second)
//			room[cY][cX] = room[nY][nX];
//		room[nY][nX] = 0;
//		cY = nY;
//		cX = nX;
//	}
//}
//
//void FilterDown() {
//	int cY = filters[1].first;
//	int cX = filters[1].second;
//	int cDir = 2;
//	while (true) {
//		int nY = cY + dir[cDir][0];
//		int nX = cX + dir[cDir][1];
//		if (nY == filters[1].first && nX == filters[1].second) break;
//		if (nY < filters[1].first || nY >= R || nX < 0 || nX >= C) {
//			cDir--;
//			if (cDir < 0) cDir = 3;
//		}
//		nY = cY + dir[cDir][0];
//		nX = cX + dir[cDir][1];
//		if (cY != filters[1].first || cX != filters[1].second)
//			room[cY][cX] = room[nY][nX];
//		room[nY][nX] = 0;
//		cY = nY;
//		cX = nX;
//	}
//}
//
//void FilterAir() {
//	FilterUp();
//	FilterDown();
//}
//
//void Solve() {
//	int curTime = 0;
//	while (curTime < T) {
//		SpreadDust();
//		FilterAir();
//		curTime++;
//	}
//	int sum = 0;
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (room[i][j] < 1) continue;
//			sum += room[i][j];
//		}
//	}
//	cout << sum;
//}
//
//int main() {
//	GetInput();
//	Solve();
//	return 0;
//}