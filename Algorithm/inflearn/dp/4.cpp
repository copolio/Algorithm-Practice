#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Brick
{
public:
    int area;
    int height;
    int weight;

    Brick(int a, int b, int c)
    {
        this->area = a;
        this->height = b;
        this->weight = c;
    }

    bool operator<(Brick a)
    {
        return this->area > a.area;
    }
};

int main()
{
    int nBrick;
    vector<Brick> bricks;

    cin >> nBrick;
    for (int i = 0; i < nBrick; i++)
    {
        int area, height, weight;
        cin >> area >> height >> weight;
        Brick c = Brick(area, height, weight);
        bricks.push_back(c);
    }

    sort(bricks.begin(), bricks.end());

    int dp[nBrick];
    dp[0] = bricks[0].height;
    int answer = dp[0];

    for (int i = 1; i < nBrick; i++)
    {
        int max = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (bricks[j].weight > bricks[i].weight && dp[j] > max)
            {
                max = dp[j];
            }
        }
        dp[i] = bricks[i].height + max;
        answer = answer > dp[i] ? answer : dp[i];
    }

    cout << answer << endl;

    return 0;
}