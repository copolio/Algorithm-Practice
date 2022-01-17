#include <string>
#include <vector>
#include <cmath>

using namespace std;

const char PERSON = 'P';
const char EMPTY = 'O';
const char PARTITION = 'X';

int getDist(const vector<int> &a, const vector<int> &b)
{
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

bool isDistancing(const vector<string> &room)
{
    int h = room.size();
    int w = room[0].size();

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (room[i][j] == PERSON)
            {
                for (int k = i + 1; k <= i + 2; k++)
                {
                    if (k == h)
                        break;
                    if (room[k][j] == PERSON)
                    {
                        if (getDist({i, j}, {k, j}) < 2)
                        {
                            return false;
                        }
                        if (getDist({i, j}, {k, j}) == 2 && room[i + 1][j] != PARTITION)
                        {
                            return false;
                        }
                    }
                }

                for (int k = j + 1; k <= j + 2; k++)
                {
                    if (k == w)
                        break;
                    if (room[i][k] == PERSON)
                    {
                        if (getDist({i, j}, {i, k}) < 2)
                        {
                            return false;
                        }
                        if (getDist({i, j}, {i, k}) == 2 && room[i][j + 1] != PARTITION)
                        {
                            return false;
                        }
                    }
                }

                if (i < h - 1 && j < w - 1 && room[i + 1][j + 1] == PERSON &&
                    (room[i][j + 1] != PARTITION || room[i + 1][j] != PARTITION))
                {
                    return false;
                }

                if (i < h - 1 && j > 0 && room[i + 1][j - 1] == PERSON &&
                    (room[i][j - 1] != PARTITION || room[i + 1][j] != PARTITION))
                {
                    return false;
                }

                if (i > 0 && j > 0 && room[i - 1][j - 1] == PERSON &&
                    (room[i][j - 1] != PARTITION || room[i - 1][j] != PARTITION))
                {
                    return false;
                }

                if (i > 0 && j < w - 1 && room[i - 1][j + 1] == PERSON &&
                    (room[i][j + 1] != PARTITION || room[i - 1][j] != PARTITION))
                {
                    return false;
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;
    for (auto place : places)
    {
        if (!isDistancing(place))
        {
            answer.push_back(0);
        }
        else
        {
            answer.push_back(1);
        }
    }
    return answer;
}