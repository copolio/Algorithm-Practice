//#include <iostream>
//#include <vector>
//using namespace std;
//
//int N, M;
//int result = 0;
//int paper[500][500] = { 0, };
//bool visited[500][500] = { false, };
//
//int Max(int x, int y) {
//	return x > y ? x : y;
//}
//
//void DFS(int x, int y, int length, int sum) {
//	visited[y][x] = true;
//	sum += paper[y][x];
//	if (length >= 4) {
//		result = Max(result, sum);
//		visited[y][x] = false;
//		return;
//	}
//	if (x < M - 1 && !visited[y][x+1]) {
//		DFS(x + 1, y, length + 1, sum);
//	}
//	if (x > 0 && !visited[y][x-1]) {
//		DFS(x - 1, y, length + 1, sum);
//	}
//	if (y < N - 1 && !visited[y+1][x]) {
//		DFS(x, y + 1, length + 1, sum);
//	}
//	if (y > 0 && !visited[y-1][x]) {
//		DFS(x, y - 1, length + 1, sum);
//	}
//	visited[y][x] = false;
//}
//
//void CheckT(int x, int y) {
//	// た
//	if (x < M - 1 && y < N - 2) {
//		int temp = paper[y][x] + paper[y + 1][x] + paper[y + 2][x] + paper[y + 1][x + 1];
//		result = Max(result, temp);
//	}
//	// で
//	if (x < M - 2 && y > 0) {
//		int temp = paper[y][x] + paper[y][x+1] + paper[y][x+2] + paper[y - 1][x + 1];
//		result = Max(result, temp);
//	}
//	// っ
//	if (x < M - 1 && y > 0 && y < N - 1) {
//		int temp = paper[y][x] + paper[y][x + 1] + paper[y + 1][x + 1] + paper[y - 1][x + 1];
//		result = Max(result, temp);
//	}
//	// ぬ
//	if (x < M - 2 && y < N - 1) {
//		int temp = paper[y][x] + paper[y][x + 1] + paper[y][x + 2] + paper[y + 1][x + 1];
//		result = Max(result, temp);
//	}
//	return;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> paper[i][j];
//		}
//	}
//
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			DFS(j, i, 1, 0);
//			CheckT(j, i);
//		}
//	}
//
//	cout << result << endl;
//
//	return 0;
//}