#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int coin[n];
    for (int i = 0; i < n; i++)
    {
        cin >> coin[i];
    }
    cin >> m;

    int dp[m + 1][n + 1] = {0};
    // cout << endl;

    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = 0;
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = 0;
            int k = i / coin[j - 1];
            int l = i % coin[j - 1];
            dp[i][j] = k + dp[l][j - 1];
            if (j > 1 && dp[i][j - 1] < dp[i][j])
                dp[i][j] = dp[i][j - 1];
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << dp[m][n] << endl;

    return 0;
}