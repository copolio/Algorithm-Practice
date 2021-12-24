#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, answer = 0;
    vector<pair<int, int>> meetings;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        meetings.push_back(make_pair(start, end));
    }

    sort(meetings.begin(), meetings.end(), [](pair<int, int> &a, pair<int, int> &b) -> bool
         {
             if (a.second == b.second)
                 return a.first < b.first;
             return a.second < b.second;
         });

    int et = 0;

    for (int i = 0; i < n; i++)
    {
        if (meetings[i].first >= et)
        {
            answer++;
            et = meetings[i].second;
        }
    }

    cout << answer << endl;

    return 0;
}