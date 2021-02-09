//#ifdef _MSC_VER
//#define _CRT_SECURE_NO_WARNINGS
//#endif
//
//#include <iostream>
//#include <cstdio>
//#include <vector>
//#include <queue>
//#include <cmath>
//
//using namespace std;
//
//int gears[4][8] = { 0, };
//int nRotation, score = 0;;
//
//void RotateGears(int gear, int dir) {
//	bool visited[4] = { false, };
//	vector<pair<int, int>> rotations;
//	queue<pair<int, int>> q;		//기어, 방향
//	q.push(make_pair(gear, dir));
//	while (!q.empty()) {
//		rotations.push_back(q.front());
//		int curGear = q.front().first;
//		int curDir = q.front().second;
//		visited[curGear] = true;
//		q.pop();
//		if (curGear + 1 < 4 && !visited[curGear + 1] && gears[curGear][2] != gears[curGear + 1][6]) {
//			q.push(make_pair(curGear + 1, curDir * -1));
//		}
//		if (curGear - 1 >= 0 && !visited[curGear - 1] && gears[curGear][6] != gears[curGear - 1][2]) {
//			q.push(make_pair(curGear - 1, curDir * -1));
//		}
//	}
//	for (int i = 0; i < rotations.size(); i++) {
//		if (rotations[i].second == 1) {
//			int temp = gears[rotations[i].first][7];
//			for (int j = 7; j > 0; j--) {
//				gears[rotations[i].first][j] = gears[rotations[i].first][j - 1];
//			}
//			gears[rotations[i].first][0] = temp;
//		}
//		else {
//			int temp = gears[rotations[i].first][0];
//			for (int j = 0; j < 7; j++) {
//				gears[rotations[i].first][j] = gears[rotations[i].first][j + 1];
//			}
//			gears[rotations[i].first][7] = temp;
//		}
//
//	}
//}
//
//void GetScore() {
//	for (int i = 0; i < 4; i++) {
//		int point = pow(2, i);
//		if (gears[i][0] == 1) {
//			score += point;
//		}
//	}
//}
//
//int main() {
//	for (int i = 0; i < 4; i++) {
//		for (int j = 0; j < 8; j++) {
//			scanf("%1d", &gears[i][j]);
//		}
//	}
//	cin >> nRotation;
//	for (int i = 0; i < nRotation; i++) {
//		int gearNum, dir;
//		cin >> gearNum >> dir;
//		RotateGears(gearNum-1, dir);
//	}
//	GetScore();
//	cout << score;
//	return 0;
//}