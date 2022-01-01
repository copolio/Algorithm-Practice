#include <iostream>
#include <vector>

using namespace std;

class data
{
public:
    int score;
    int time;
    data(int a, int b)
    {
        this->score = a;
        this->time = b;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<data> info;
    for (int i = 0; i < n; i++)
    {
        int score, time;
        cin >> score >> time;
        info.push_back(data(score, time));
    }

    int dp[m + 1] = {
        0,
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= info[i].time; j--)
        {

            dp[j] = dp[j] > dp[j - info[i].time] + info[i].score ? dp[j] : dp[j - info[i].time] + info[i].score;
        }
    }

    cout << dp[m] << endl;
    return 0;
}