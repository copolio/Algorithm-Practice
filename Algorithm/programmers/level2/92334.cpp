#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer;
    unordered_map<string, set<string>> reportByUser;
    unordered_map<string, int> userBanCount;

    for (string user : id_list)
    {
        userBanCount[user] = 0;
    }

    for (int i = 0; i < report.size(); i++)
    {
        int pos = report[i].find(' ');
        string reporter = report[i].substr(0, pos);
        string reported = report[i].substr(pos + 1);
        if (reportByUser[reporter].count(reported) == 0)
        {
            userBanCount[reported]++;
        }
        reportByUser[reporter].insert(reported);
    }

    for (string user : id_list)
    {
        int mail = 0;
        for (string reported : reportByUser[user])
        {
            if (userBanCount[reported] >= k)
            {
                mail++;
            }
        }
        answer.push_back(mail);
    }

    return answer;
}