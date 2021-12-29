#include <iostream>

using namespace std;

int main()
{
    int n, answer = 1;
    cin >> n;

    int data[n];
    int dp[n];

    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (data[j] >= data[i])
            {
                continue;
            }
            else
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        answer = answer > dp[i] ? answer : dp[i];
    }

    cout << answer << endl;

    return 0;
}