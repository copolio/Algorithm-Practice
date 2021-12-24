#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    vector<pair<int, int>> visitors;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int arrive, leave;
        cin >> arrive >> leave;
        visitors.push_back(make_pair(arrive, leave));
    }

    sort(visitors.begin(), visitors.end(),
         [](pair<int, int> a, pair<int, int> b) -> bool
         {
             if (a.first == b.first)
                 return a.second < b.second;
             return a.first < b.first;
         });

    vector<int> time(73);

    for (int i = 0; i < n; i++)
    {
        for (int j = visitors[i].first; j < visitors[i].second; j++)
        {
            time[j] += 1;
        }
    }

    int answer = *max_element(time.begin(), time.end());

    cout << answer << endl;

    return 0;
}