#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	int M = key.size();
	int N = lock.size();
	for (int time = 0; time < 4; time++) {
		//시계방향으로 네번 돌려서 테스트를 해보는거다.
		//newkey 초기화
		vector<vector<int>> newkey(M, vector<int>(M, 0));

		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				newkey[j][M - 1 - i] = key[i][j];
		//        for(int i=0;i<M;i++)
		//            for(int j=0; j<M;j++)
		//                cout<<newkey[i][j];
				//원래키 업데이트
		for (int i = 0; i < M; i++)
			for (int j = 0; j < M; j++)
				key[i][j] = newkey[i][j];

		//이제 자물쇠랑 열쇠를 맞춰보는 작업을 해야한다. 근데 어떡해야 하징?
		//총 경우의 수는 (N+M-1)^2의 경우의 수가 생긴다.
		for (int i = 0; i < N + M - 1; i++) {
			for (int j = 0; j < N + M - 1; j++) {
				//큰 자물쇠 newlock 초기화
				vector<vector<int>> newlock(2 * M - 2 + N, vector<int>(2 * M - 2 + N, 0));

				for (int ii = 0; ii < N; ii++)
				{
					for (int jj = 0; jj < N; jj++)
					{
						newlock[ii + M - 1][jj + M - 1] = lock[ii][jj];
					}
				}
				//newlock이랑 newkey 합치기
				for (int ii = 0; ii < M; ii++) {
					for (int jj = 0; jj < M; jj++) {
						newlock[ii + i][jj + j] += newkey[ii][jj];
					}
				}
				//newlock의 가운데부분 보기. 이제 맞나 안맞나를 판단하는거다.
				int count = 0;
				for (int ii = M - 1; ii < M + N - 1; ii++) {
					for (int jj = M - 1; jj < M + N - 1; jj++) {
						if (newlock[ii][jj] == 1) {
							count++;
						}
					}
				}
				if (count == N * N) {
					return true;
				}
			}
		}
	}
	return false;
}