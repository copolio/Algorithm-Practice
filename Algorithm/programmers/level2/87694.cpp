#include <string>
#include <vector>
#include <queue>

using namespace std;

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isInside(vector<int> rectangle, vector<int> point)
{
    if (point[0] > rectangle[0] && point[0] < rectangle[2])
    {
        return point[1] > rectangle[1] && point[1] < rectangle[3];
    }
    if (point[1] > rectangle[1] && point[1] < rectangle[3])
    {
        return point[0] > rectangle[0] && point[0] < rectangle[2];
    }
    return false;
}

bool isBorder(vector<int> rectangle, vector<int> point)
{
    if (point[0] == rectangle[0] || point[0] == rectangle[2])
    {
        return point[1] >= rectangle[1] && point[1] <= rectangle[3];
    }
    if (point[1] == rectangle[1] || point[1] == rectangle[3])
    {
        return point[0] >= rectangle[0] && point[0] <= rectangle[2];
    }
    return false;
}

bool isMovable(vector<int> rectangle, vector<int> pt1, vector<int> pt2)
{
    return isBorder(rectangle, pt1) && isBorder(rectangle, pt2);
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY)
{
    int answer = 0;
    queue<vector<int>> q;
    for (int i = 0; i < rectangle.size(); i++)
    {
        rectangle[i][0] *= 2;
        rectangle[i][1] *= 2;
        rectangle[i][2] *= 2;
        rectangle[i][3] *= 2;
    }
    bool visited[102][102] = {
        false,
    };

    q.push({characterX * 2, characterY * 2, 0});
    visited[characterX * 2][characterY * 2] = true;

    while (!q.empty())
    {
        vector<int> pos = q.front();
        q.pop();

        if (pos[0] == itemX * 2 && pos[1] == itemY * 2)
        {
            answer = pos[2] / 2;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            vector<int> newPos = {pos[0] + moves[i][0], pos[1] + moves[i][1], pos[2] + 1};
            if (visited[newPos[0]][newPos[1]])
            {
                continue;
            }

            bool border = false;
            bool inside = false;
            bool movable = false;
            for (int j = 0; j < rectangle.size(); j++)
            {
                if (isMovable(rectangle[j], pos, newPos))
                {
                    movable = true;
                }
                if (isBorder(rectangle[j], newPos))
                {
                    border = true;
                }
                if (isInside(rectangle[j], newPos))
                {
                    inside = true;
                    break;
                }
            }
            if (inside)
                continue;
            if (!movable)
                continue;
            if (border)
            {
                visited[newPos[0]][newPos[1]] = true;
                q.push(newPos);
            }
        }
    }

    return answer;
}