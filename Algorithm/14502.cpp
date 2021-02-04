//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//int N, M, maxArea = 0;
//int labMap[8][8] = { 0, }, temp[8][8] = { 0, };
//bool visited[8][8] = { false, };
//queue<pair<int, int>> q;
//void BFS() {
//	memcpy(temp, labMap, sizeof(labMap));
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (temp[i][j] == 2) {
//				q.push(make_pair(i, j));
//			}
//		}
//	}
//	while (!q.empty()) {
//		int y = q.front().first;
//		int x = q.front().second;
//		q.pop();
//		if (x > 0 && temp[y][x - 1] == 0) {
//			q.push(make_pair(y, x - 1));
//			temp[y][x - 1] = 2;
//		}
//		if (x < M - 1 && temp[y][x + 1] == 0) {
//			q.push(make_pair(y, x + 1));
//			temp[y][x + 1] = 2;
//		}
//		if (y > 0 && temp[y - 1][x] == 0) {
//			q.push(make_pair(y - 1, x));
//			temp[y - 1][x] = 2;
//		}
//		if (y < N - 1 && temp[y + 1][x] == 0) {
//			q.push(make_pair(y + 1, x));
//			temp[y + 1][x] = 2;
//		}
//	}
//}
//void GetArea() {
//	int area = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (temp[i][j] == 0) area++;
//		}
//	}
//	maxArea = area > maxArea ? area : maxArea;
//	return;
//}
//void SetWall(int y, int x, int cnt) {
//	labMap[y][x] = 1;
//	if (cnt == 3) {
//		BFS();
//		GetArea();
//		labMap[y][x] = 0;
//		return;
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (labMap[i][j] == 0 && !visited[i][j]) {
//				visited[i][j] = true;
//				SetWall(i, j, cnt + 1);
//				visited[i][j] = false;
//			}
//		}
//	}
//	labMap[y][x] = 0;
//}
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> labMap[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			if (labMap[i][j] == 0) {
//				SetWall(i, j, 1);
//				visited[i][j] = true;
//			}
//		}
//	}
//	cout << maxArea;
//	return 0;
//}