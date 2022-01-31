#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> graph;

int dfs(int n, int pos) {
    vector<bool> visited(n+1, false);
    visited[pos] = true;
    int min = n - 1;
    for(auto newPos : graph[pos]) {
        int len = 0;
        queue<int> q;
        visited[newPos] = true;
        q.push(newPos);
        while(!q.empty()) {
            int next = q.front();
            q.pop();
            len++;
            for (auto nextNext : graph[next]) {
                if (visited[nextNext]) continue;
                q.push(nextNext);
                visited[nextNext] = true;
            }
        }
        min = min > abs(n - 2 * len) ? abs(n - 2 * len) : min; 
    }
    return min;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = n - 1;

    for (auto wire : wires)
    {
        int n1 = wire[0];
        int n2 = wire[1];
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    for (int i = 1; i <= n; i++) {
        if (graph[i].size() < 2) continue;
        int min = dfs(n, i);
        answer = answer > min ? min : answer;
    }
    return answer;
}