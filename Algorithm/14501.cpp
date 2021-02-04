//#include <iostream>
//#include <vector>
//using namespace std;
//int N;
//vector<pair<int, int>> schedule;
//int dp[16] = { 0, };
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int T, P;
//		cin >> T >> P;
//		schedule.push_back(make_pair(T, P));
//	}
//	for (int i = 0; i < N; i++) {
//		if (i + schedule[i].first <= N) {
//			for (int j = i + schedule[i].first; j <= N; j++) {
//				dp[j] = dp[i] + schedule[i].second > dp[j] ? dp[i] + schedule[i].second : dp[j];
//			}
//		}
//	}
//	//디버깅용 출력
//	//for (int i = 0; i <= N; i++) {
//	//	cout << dp[i] << " ";
//	//}
//	//cout << endl;
//	cout << dp[N];
//	return 0;
//}