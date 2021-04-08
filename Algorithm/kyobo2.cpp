//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//	vector<int> vNumBetween;
//	//입력용 상수
//	int r1 = 1000;
//	int r2 = 10000;
//	int n = 0;
//	int order = 250; 
//
//	//입력받을시 주석해제
//	//cin >> r1 >> r2 >> n >> order;
//
//	//루프를 돌며 r1부터 r2사이 모든 숫자를 확인
//	for (int i = r1; i <= r2; i++) {
//		int num = i;
//		//i번째 숫자를 10으로 나눈 나머지가 자릿수가 된다. 
//		//숫자를 10으로 나눈 값이 0이 될때까지(=모든 자릿수를 확인할 때까지) 반복한다.
//		//자릿수가 n과 같을시 n이 포함된 수를 저장하는 vNumBetween 배열에 저장한다.
//		while (num != 0) {
//			int digit = num % 10;
//			num /= 10;
//			if (digit == n) {
//				vNumBetween.push_back(i);
//				continue;
//			}
//		}
//	}
//	cout << "Count : " << vNumBetween.size() << endl;
//	cout << order << "번째 " << n << "을 포함한 값은 : ";
//	//order이 vNumBetween배열의 크기보다 크다면 order번째 n값이 없음으로 -1을 출력하고, 그렇지 않은 경우 답을 출력한다.
//	if (vNumBetween.size() < order) {
//		cout << -1 << endl;
//	}
//	else {
//		cout << vNumBetween[order - 1] << endl;
//	}
//
//	return 0;
//}