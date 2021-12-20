#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m, n;
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<vector<int>> map;
vector<vector<bool>> visited;

int bfs()
{
    int answer = 0;
    queue<pair<int, int>> tomatoes;
    bool finished = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1)
            {
                tomatoes.push(make_pair(i, j));
                visited[i][j] = true;
            }
            else if (map[i][j] == 0)
            {
                finished = false;
            }
        }
    }

    if (finished)
        return answer;

    while (!tomatoes.empty())
    {
        queue<pair<int, int>> newTomatoes;
        while (!tomatoes.empty())
        {
            pair<int, int> tomato = tomatoes.front();
            tomatoes.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextY = tomato.first + moves[i][0];
                int nextX = tomato.second + moves[i][1];
                if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= m)
                {
                    continue;
                }
                if (map[nextY][nextX] == 1 || map[nextY][nextX] == -1)
                {
                    continue;
                }
                if (visited[nextY][nextX])
                {
                    continue;
                }
                map[nextY][nextX] = 1;
                visited[nextY][nextX] = true;
                newTomatoes.push(make_pair(nextY, nextX));
            }
        }
        tomatoes = newTomatoes;
        answer++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return answer - 1;
}

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        vector<bool> vrow;
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            row.push_back(num);
            vrow.push_back(false);
        }
        map.push_back(row);
        visited.push_back(vrow);
    }

    int answer = bfs();

    cout << answer << endl;

    return 0;
}