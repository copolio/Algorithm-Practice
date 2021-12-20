#include <iostream>
#include <queue>

using namespace std;

int map[7][7];
bool visited[7][7];
int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int answer = -1;

void bfs()
{
    priority_queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(0, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<int, pair<int, int>> cur = q.top();
        q.pop();
        int dist = cur.first;
        pair<int, int> pos = cur.second;
        if (pos.first == 6 && pos.second == 6)
        {
            answer = dist;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nextY = pos.first + moves[i][0];
            int nextX = pos.second + moves[i][1];
            if (nextY < 0 || nextY > 6 || nextX < 0 || nextX > 6)
            {
                continue;
            }
            if (map[nextY][nextX] == 1)
            {
                continue;
            }
            if (!visited[nextY][nextX])
            {
                visited[nextY][nextX] = true;
                q.push(make_pair(dist + 1, make_pair(nextY, nextX)));
            }
        }
    }
}

int main()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cin >> map[i][j];
        }
    }

    bfs();

    cout << answer;

    return 0;
}