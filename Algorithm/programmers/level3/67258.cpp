#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems)
{
    vector<int> answer(2);
    unordered_set<string> kind;
    unordered_map<string, int> count;
    int minDist = gems.size() + 1;

    for (string g : gems)
    {
        kind.insert(g);
    }

    int start = 0, end = 0;
    while (true)
    {
        bool updated = false;
        for (int i = end; i < gems.size(); i++)
        {
            count[gems[i]]++;
            if (count.size() == kind.size())
            {
                end = i;
                updated = true;
                break;
            }
        }

        if (!updated)
            break;

        for (int i = start; i < gems.size(); i++)
        {
            if (count[gems[i]] == 1)
            {
                start = i;
                break;
            }
            count[gems[i]]--;
        }

        if (end - start < minDist)
        {
            minDist = end - start;
            answer[0] = start + 1;
            answer[1] = end + 1;
        }

        count.erase(gems[start]);
        start++;
        end++;
    }

    return answer;
}