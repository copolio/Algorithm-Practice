#include <string>
#include <vector>

using namespace std;

int maxMoves = 0;

void dfs(const vector<vector<int>> &dungeons, vector<bool> visited, int fatigue, int cnt)
{
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (!visited[i] && fatigue >= dungeons[i][0])
        {
            visited[i] = true;
            dfs(dungeons, visited, fatigue - dungeons[i][1], cnt + 1);
            visited[i] = false;
        }
    }
    maxMoves = maxMoves < cnt ? cnt : maxMoves;
}

int solution(int k, vector<vector<int>> dungeons)
{
    vector<bool> visited(dungeons.size(), false);
    dfs(dungeons, visited, k, 0);
    int answer = maxMoves;

    return answer;
}