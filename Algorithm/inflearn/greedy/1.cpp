#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int n, nLosers = 0;
    vector<int> heights;
    vector<int> weights;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int height, weight;
        cin >> height >> weight;
        heights.push_back(height);
        weights.push_back(weight);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (heights[i] < heights[j] && weights[i] < weights[j])
            {
                nLosers++;
                break;
            }
        }
    }

    cout << n - nLosers << endl;
    return 0;
}