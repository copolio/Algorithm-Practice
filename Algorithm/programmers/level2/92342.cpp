#include <string>
#include <vector>
#include <queue>

using namespace std;

int getDiff(vector<int> apeach, vector<int> ryan)
{
    int aScore = 0;
    int rScore = 0;
    for (int i = 0; i < 10; i++)
    {
        if (apeach[i] == 0 && ryan[i] == 0)
            continue;
        if (apeach[i] >= ryan[i])
        {
            aScore += 10 - i;
        }
        else
        {
            rScore += 10 - i;
        }
    }

    return rScore - aScore;
}

bool compareAnswer(vector<int> a, vector<int> b)
{
    for (int i = 10; i >= 0; i--)
    {
        if (a[i] > b[i])
        {
            return true;
        }
        else if (a[i] == b[i])
            continue;
        else
            return false;
    }
    return false;
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    int maxDiff = -1;

    queue<pair<vector<int>, int>> q;
    q.push(make_pair(answer, n));
    while (!q.empty())
    {
        vector<int> ryan = q.front().first;
        int nRemain = q.front().second;
        int cur = ryan.size();

        q.pop();

        if (cur == 11)
        {
            if (nRemain > 0)
                ryan[10] = nRemain;
            int diff = getDiff(info, ryan);
            if (diff <= 0)
                continue;
            if (diff > maxDiff)
            {
                answer = ryan;
                maxDiff = diff;
            }
            else if (diff == maxDiff)
            {
                if (compareAnswer(ryan, answer))
                {
                    answer = ryan;
                }
            }
            continue;
        }

        int nNeeded = info[cur] + 1;
        if (nNeeded > nRemain)
        {
            ryan.push_back(0);
            q.push(make_pair(ryan, nRemain));
        }
        else
        {
            ryan.push_back(0);
            q.push(make_pair(ryan, nRemain));

            ryan.pop_back();
            ryan.push_back(nNeeded);
            q.push(make_pair(ryan, nRemain - nNeeded));
        }
    }

    if (maxDiff < 0)
    {
        answer.push_back(maxDiff);
    }
    return answer;
}