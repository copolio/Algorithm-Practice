#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;
    vector<bool> visited(win_nums.size());
    int cur = 0;
    int nMatch = 0;
    int nHide = 0;
    for (auto lotto : lottos)
    {
        if (lotto == 0)
        {
            nHide++;
            continue;
        }
        for (int i = 0; i < win_nums.size(); i++)
        {
            if (visited[i])
                continue;
            if (lotto == win_nums[i])
            {
                nMatch++;
                visited[i] = true;
                break;
            }
        }
    }
    int best = nMatch + nHide < 1 ? 1 : nMatch + nHide;
    int worst = nMatch < 1 ? 1 : nMatch;

    answer.push_back(7 - best);
    answer.push_back(7 - worst);
    return answer;
}