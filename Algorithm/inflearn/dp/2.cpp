#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[n + 2];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n + 1] << endl;

    return 0;
}