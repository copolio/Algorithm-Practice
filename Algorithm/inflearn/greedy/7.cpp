#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent, parent[x]);
}

int main()
{
    int nCity, nRoad, answer = 0;
    vector<vector<int>> inputs;

    cin >> nCity >> nRoad;
    vector<int> cities(nCity + 1);

    for (int i = 0; i <= nCity; i++)
    {
        cities[i] = i;
    }

    for (int i = 0; i < nRoad; i++)
    {
        vector<int> input;
        int city1, city2, cost;
        cin >> city1 >> city2 >> cost;
        input.push_back(city1);
        input.push_back(city2);
        input.push_back(cost);
        inputs.push_back(input);
    }

    sort(inputs.begin(), inputs.end(),
         [](const vector<int> &input1, const vector<int> &input2) -> bool
         { return input1[2] < input2[2]; });

    for (auto cur : inputs)
    {
        int par1 = getParent(cities, cur[0]);
        int par2 = getParent(cities, cur[1]);
        if (par1 == par2)
        {
            continue;
        }
        if (par1 < par2)
        {
            cities[par2] = par1;
        }
        else
        {
            cities[par1] = par2;
        }
        answer += cur[2];
    }

    cout << answer << endl;

    return 0;
}