#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<pair<int, int>> offers;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, d;
        cin >> m >> d;
        offers.push_back(make_pair(m, d));
    }

    sort(offers.begin(), offers.end(),
         [](pair<int, int> a, pair<int, int> b) -> bool
         {
             if (a.second == b.second)
                 return a.first > b.first;
             return a.second > b.second;
         });

    int j = 0, answer = 0;
    int max = offers[0].second;
    priority_queue<int> pq;

    for (int i = max; i > 0; i--)
    {
        for (; j < n; j++)
        {
            if (offers[j].second < i)
                break;
            pq.push(offers[j].first);
        }
        if (!pq.empty())
        {
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer << endl;

    return 0;
}