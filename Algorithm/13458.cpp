//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	long long N, B, C;
//	long long minNumOfSupervisors = 0;
//	vector<int> A;
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int a;
//		cin >> a;
//		A.push_back(a);
//	}
//	cin >> B >> C;
//	for (int i = 0; i < A.size(); i++) {
//		long long remainingStudents = A[i];
//		remainingStudents -= B;
//		minNumOfSupervisors++;
//		if (remainingStudents > 0) {
//			if (remainingStudents % C == 0) {
//				minNumOfSupervisors += remainingStudents / C;
//			}
//			else {
//				minNumOfSupervisors += remainingStudents / C + 1;
//			}
//		}
//	}
//	cout << minNumOfSupervisors;
//	return 0;
//}