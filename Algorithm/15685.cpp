//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int N, answer = 0;
//bool visited[101][101] = { false, };
//int moveDir[4][2] = { { 0, 1 }, { -1, 0 }, { 0, -1 }, { 1, 0 } };
//
//int main() {
//	cin >> N;
//
//	for (int i = 0; i < N; i++) {
//		int x, y, d, g;
//		vector<int> curves;
//
//		cin >> x >> y >> d >> g;
//
//		curves.push_back(d);
//
//		for (int j = 0; j < g; j++) {
//			vector<int> temp = curves;
//			for (int k = temp.size() - 1; k >= 0; k--) {
//				curves.push_back((temp[k] + 1) % 4);
//			}
//		}
//
//		visited[y][x] = true;
//
//		for (int j = 0; j < curves.size(); j++) {
//			y += moveDir[curves[j]][0];
//			x += moveDir[curves[j]][1];
//
//			if (x >= 0 && x <= 100 && y >= 0 && y <= 100)
//				visited[y][x] = true;
//		}
//	}
//
//	for (int i = 0; i < 101; i++) {
//		for (int j = 0; j < 101; j++) {
//			if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) answer++;
//		}
//	}
//
//	cout << answer;
//	return 0;
//}