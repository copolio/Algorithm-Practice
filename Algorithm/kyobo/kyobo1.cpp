#include <iostream>
#include <vector>

using namespace std;

int dp[11] = { 1, 0, 3, 0, };

//�ش� ������ ���� ���α׷����� �̿��� ��������� Ǯ �� �ִ�.
//n�� Ȧ�� �� ��쿣 �������� ä�� �� ������, ¦���� ��쿡�� ����.
//DP�� ��ȭ���� f(n) = 3 * f(n-2) + 2 * f(n-4) + 2 * f(n-6) + ,,, + 2 * f(2) + 2�̴�.
//�̸� �ڵ�� �����ϸ� ������ ����.

int Solve(int n) {
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (n == 2) return 3;
	if (dp[n]) return dp[n];
	else {
		dp[n] = 3 * Solve(n - 2);
		for (int i = 4; i <= n; i += 2) {
			dp[n] += 2 * Solve(n - i);
		}
		return dp[n];
	}
}

int main() {
	int n, answer;
	cin >> n;

	answer = Solve(n);
	cout << answer << endl;

	return 0;
}