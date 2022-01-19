#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Node
{
    int x;
    int y;
    int dir;
    char kind;

    void moveLeft()
    {
        dir = (dir + 1) % 4;
        x = x + dirs[dir][0];
        y = y + dirs[dir][1];
    }

    void moveRight()
    {
        dir = dir - 1 < 0 ? 3 : dir - 1;
        x = x + dirs[dir][0];
        y = y + dirs[dir][1];
    }

    void moveStraight()
    {
        x = x + dirs[dir][0];
        y = y + dirs[dir][1];
    }
};

int getCycle(const vector<string> &grid, vector<vector<vector<bool>>> &visited, Node &c, int dist)
{
    if (visited[c.y][c.x][c.dir])
        return dist;
    visited[c.y][c.x][c.dir] = true;
    if (c.kind == 'L')
        c.moveLeft();
    else if (c.kind == 'R')
        c.moveRight();
    else
        c.moveStraight();
    if (c.x < 0)
        c.x = grid[0].size() - 1;
    if (c.x >= grid[0].size())
        c.x = 0;
    if (c.y < 0)
        c.y = grid.size() - 1;
    if (c.y >= grid.size())
        c.y = 0;
    c.kind = grid[c.y][c.x];
    return getCycle(grid, visited, c, dist + 1);
}

vector<int> solution(vector<string> grid)
{
    vector<int> answer;
    vector<vector<vector<bool>>> visited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(4, false)));

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (!visited[i][j][k])
                {
                    Node node;
                    node.x = j;
                    node.y = i;
                    node.dir = k;
                    node.kind = grid[i][j];
                    answer.push_back(getCycle(grid, visited, node, 0));
                }
            }
        }
    }
    sort(answer.begin(), answer.end());

    return answer;
}
