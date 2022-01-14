#include <vector>
#include <queue>

using namespace std;

int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node
{
    int y;
    int x;
    int dist;
};

struct compare
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.dist > b.dist;
    }
};

int solution(vector<vector<int>> maps)
{
    int answer = -1;
    int height = maps.size();
    int width = maps[0].size();
    priority_queue<Node, vector<Node>, compare> pq;

    vector<vector<bool>> visited(height, vector<bool>(width, false));
    visited[0][0] = true;
    Node cur;
    cur.y = 0;
    cur.x = 0;
    cur.dist = 1;
    pq.push(cur);
    while (!pq.empty())
    {
        Node pos = pq.top();
        pq.pop();
        if (pos.y == height - 1 && pos.x == width - 1)
        {
            answer = pos.dist;
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            Node next;
            int nextY = pos.y + moves[i][0];
            int nextX = pos.x + moves[i][1];
            if (nextY < 0 || nextY >= height)
                continue;
            if (nextX < 0 || nextX >= width)
                continue;
            if (maps[nextY][nextX] == 0)
                continue;
            if (visited[nextY][nextX])
                continue;

            next.y = nextY;
            next.x = nextX;
            next.dist = pos.dist + 1;
            visited[nextY][nextX] = true;
            pq.push(next);
        }
    }

    return answer;
}