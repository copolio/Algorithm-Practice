#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, m, answer = 1000000000;
vector<vector<int>> dists;
vector<pair<int, int>> pizzaStores;
vector<pair<int, int>> houses;

int dist(pair<int, int> x, pair<int, int> y)
{
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main()
{
    vector<bool> visited;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            int type;
            cin >> type;
            if (type == 2)
            {
                pizzaStores.push_back(make_pair(i, j));
            }
            else if (type == 1)
            {
                houses.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < pizzaStores.size(); i++)
    {
        visited.push_back(false);
    }

    for (int i = 0; i < m; i++)
    {
        visited[i] = true;
    }

    sort(visited.begin(), visited.end());

    for (int i = 0; i < houses.size(); i++)
    {
        vector<int> row;
        for (int j = 0; j < pizzaStores.size(); j++)
        {
            row.push_back(dist(pizzaStores[j], houses[i]));
        }
        dists.push_back(row);
    }

    do
    {
        int sum = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            int minDist = 1000000;
            for (int j = 0; j < pizzaStores.size(); j++)
            {
                if (visited[j])
                {
                    minDist = minDist > dists[i][j] ? dists[i][j] : minDist;
                }
            }
            sum += minDist;
        }
        answer = answer > sum ? sum : answer;
        // cout << sum << endl;
    } while (next_permutation(visited.begin(), visited.end()));

    cout << answer << endl;

    return 0;
}