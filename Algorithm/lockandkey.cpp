//#include <string>
//#include <vector>
//#include <iostream>
//
//using namespace std;
//
//bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
//	bool answer = false;
//	int M = key.size();
//	int N = lock.size();
//	for (int time = 0; time < 4; time++) {
//		//�ð�������� �׹� ������ �׽�Ʈ�� �غ��°Ŵ�.
//		//newkey �ʱ�ȭ
//		vector<vector<int>> newkey(M, vector<int>(M, 0));
//
//		for (int i = 0; i < M; i++)
//			for (int j = 0; j < M; j++)
//				newkey[j][M - 1 - i] = key[i][j];
//		//        for(int i=0;i<M;i++)
//		//            for(int j=0; j<M;j++)
//		//                cout<<newkey[i][j];
//				//����Ű ������Ʈ
//		for (int i = 0; i < M; i++)
//			for (int j = 0; j < M; j++)
//				key[i][j] = newkey[i][j];
//
//		//���� �ڹ���� ���踦 ���纸�� �۾��� �ؾ��Ѵ�. �ٵ� ��ؾ� ��¡?
//		//�� ����� ���� (N+M-1)^2�� ����� ���� �����.
//		for (int i = 0; i < N + M - 1; i++) {
//			for (int j = 0; j < N + M - 1; j++) {
//				//ū �ڹ��� newlock �ʱ�ȭ
//				vector<vector<int>> newlock(2 * M - 2 + N, vector<int>(2 * M - 2 + N, 0));
//
//				for (int ii = 0; ii < N; ii++)
//				{
//					for (int jj = 0; jj < N; jj++)
//					{
//						newlock[ii + M - 1][jj + M - 1] = lock[ii][jj];
//					}
//				}
//				//newlock�̶� newkey ��ġ��
//				for (int ii = 0; ii < M; ii++) {
//					for (int jj = 0; jj < M; jj++) {
//						newlock[ii + i][jj + j] += newkey[ii][jj];
//					}
//				}
//				//newlock�� ����κ� ����. ���� �³� �ȸ³��� �Ǵ��ϴ°Ŵ�.
//				int count = 0;
//				for (int ii = M - 1; ii < M + N - 1; ii++) {
//					for (int jj = M - 1; jj < M + N - 1; jj++) {
//						if (newlock[ii][jj] == 1) {
//							count++;
//						}
//					}
//				}
//				if (count == N * N) {
//					return true;
//				}
//			}
//		}
//	}
//	return false;
//}