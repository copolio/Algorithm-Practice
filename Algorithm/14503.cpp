#include <iostream>
#include <queue>
using namespace std;
int N, M, r, c, d, destR, destC, cleanedArea = 0, rotCnt = 0;
int roomMap[50][50] = { 0, };	// 0 = ºóÄ­, 1 = º®, 2 = Ã»¼ÒµÊ
queue<pair<int, int>> q;
void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << roomMap[i][j];
		}
		cout << endl;
	}
	cout << endl;

	cout << r << " " << c << endl;
}
int main() {
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> roomMap[i][j];

	q.push(make_pair(r, c));
	roomMap[r][c] = 2;
	cleanedArea++;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		d--;
		if (d < 0) d = 3;
		switch (d) {
		case 0:
			destR = r - 1;
			destC = c;
			break;
		case 1:
			destR = r;
			destC = c + 1;
			break;
		case 2:
			destR = r + 1;
			destC = c;
			break;
		case 3:
			destR = r;
			destC = c - 1;
			break;
		}
		if (destR < 0 || destR >= N || destC < 0 || destC >= M) continue;
		if (roomMap[destR][destC] == 0) {
			r = destR;
			c = destC;
			q.push(make_pair(r, c));
			roomMap[r][c] = 2;
			cleanedArea++;
			rotCnt = 0;
		}
		else {
			rotCnt++;
			if (rotCnt >= 4) {
				switch (d) {
				case 0:
					destR = r + 1;
					destC = c;
					break;
				case 1:
					destR = r;
					destC = c - 1;
					break;
				case 2:
					destR = r - 1;
					destC = c;
					break;
				case 3:
					destR = r;
					destC = c + 1;
					break;
				}
				if (roomMap[destR][destC] == 1) break;
				r = destR;
				c = destC;
			}
			q.push(make_pair(r, c));
		}
		Print();

	}
	cout << cleanedArea;
	return 0;
}