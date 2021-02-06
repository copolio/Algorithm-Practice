//#include <iostream>
//using namespace std;
//
//int n, m, cnt = 0;
//int map[50][50];
//
//int nexty[4] = { -1, 0, 1, 0 };
//int nextx[4] = { 0, 1, 0, -1 };
//
//int backy[4] = { 1, 0, -1, 0 };
//int backx[4] = { 0, -1, 0, 1 };
//
//void dfs(int y, int x, int d) {
//	if (map[y][x] == 0) {
//		cnt++;
//		map[y][x] = 2;
//	}
//
//	for (int k = d - 1; k > d - 5; k--) {
//		int newk = (k + 4) % 4;
//		int newy = y + nexty[newk];
//		int newx = x + nextx[newk];
//
//		if (newy < 0 || newy > n - 1 || newx < 0 || newx > m - 1) continue;
//
//		if (map[newy][newx] == 0) {
//			dfs(newy, newx, newk);
//			return;
//		}
//	}
//
//	if (map[y + backy[d]][x + backx[d]] == 1) return;
//	else dfs(y + backy[d], x + backx[d], d);
//}
//
//int main() {
//	int r, c, d;
//	cin >> n >> m >> r >> c >> d;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> map[i][j];
//		}
//	}
//	dfs(r, c, d);
//	cout << cnt;
//	return 0;
//}