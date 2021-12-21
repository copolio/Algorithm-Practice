#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, answer = 0;
vector<vector<int>> map;
vector<vector<bool>> visited;
int moves[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nextY = cur.first + moves[i][0];
            int nextX = cur.second + moves[i][1];
            if (nextY < 0 || nextY >= n)
                continue;
            if (nextX < 0 || nextX >= n)
                continue;
            if (visited[nextY][nextX])
                continue;
            if (map[nextY][nextX] == 0)
                continue;
            q.push(make_pair(nextY, nextX));
            visited[nextY][nextX] = true;
        }
    }
}

int main()
{

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        vector<bool> vrow;
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            row.push_back(num);
            vrow.push_back(false);
        }
        map.push_back(row);
        visited.push_back(vrow);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && map[i][j] == 1)
            {
                bfs(i, j);
                answer++;
            }
        }
    }

    cout << answer << endl;

    return 0;
}