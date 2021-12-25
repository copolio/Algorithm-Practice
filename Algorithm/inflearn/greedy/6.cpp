#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

map<int, set<int>> friends;

bool bfs(int start, int end, vector<bool> visited)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    bool hasFound = false;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == end)
        {
            hasFound = true;
            break;
        }
        visited[cur] = true;
        for (auto c : friends[cur])
        {
            if (!visited[c])
            {
                q.push(c);
            }
        }
    }

    return hasFound;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
    }

    int input1, input2;
    cin >> input1 >> input2;
    vector<bool> visited(n + 1);

    bool answer = bfs(input1, input2, visited);

    if (answer)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}