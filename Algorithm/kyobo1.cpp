//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int dp[11] = { 1, 0, 3, 0, };
//
////해당 문제는 동적 프로그래밍을 이용해 재귀적으로 풀 수 있다.
////n이 홀수 인 경우엔 보드판을 채울 수 없으며, 짝수인 경우에만 가능.
////DP의 점화식은 f(n) = 3 * f(n-2) + 2 * f(n-4) + 2 * f(n-6) + ,,, + 2 * f(2) + 2이다.
////이를 코드로 구현하면 다음과 같다.
//
//int Solve(int n) {
//	if (n == 0) return 1;
//	if (n == 1) return 0;
//	if (n == 2) return 3;
//	if (dp[n]) return dp[n];
//	else {
//		dp[n] = 3 * Solve(n - 2);
//		for (int i = 4; i <= n; i += 2) {
//			dp[n] += 2 * Solve(n - i);
//		}
//		return dp[n];
//	}
//}
//
//int main() {
//	int n, answer;
//	cin >> n;
//
//	answer = Solve(n);
//	cout << answer << endl;
//
//	return 0;
//}