#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;

    for (string cond : query)
    {
        auto found = cond.find(" and ");
        string lang = cond.substr(0, found);

        auto temp = found + 5;
        found = cond.find(" and ", temp);
        string pos = cond.substr(temp, found - temp);

        temp = found + 5;
        found = cond.find(" and ", temp);
        string career = cond.substr(temp, found - temp);

        temp = found + 5;
        found = cond.find(" ", temp);
        string food = cond.substr(temp, found - temp);

        int score = stoi(cond.substr(found + 1));

        int cnt = 0;

        for (string applicant : info)
        {
            auto foundA = applicant.find(" ");
            string langA = applicant.substr(0, foundA);

            auto temp = applicant.find(" ", foundA + 1);
            string posA = applicant.substr(foundA + 1, temp - foundA - 1);

            foundA = temp;
            temp = applicant.find(" ", foundA + 1);
            string careerA = applicant.substr(foundA + 1, temp - foundA - 1);

            foundA = temp;
            temp = applicant.find(" ", foundA + 1);
            string foodA = applicant.substr(foundA + 1, temp - foundA - 1);

            foundA = temp;
            temp = applicant.find(" ", foundA + 1);
            int scoreA = stoi(applicant.substr(foundA + 1, temp - foundA - 1));

            if (langA != lang && lang != "-")
            {
                continue;
            }
            if (posA != pos && pos != "-")
            {
                continue;
            }
            if (careerA != career && career != "-")
            {
                continue;
            }
            if (foodA != food && food != "-")
            {
                continue;
            }
            if (scoreA < score)
            {
                continue;
            }
            cnt++;
        }

        answer.push_back(cnt);
    }

    return answer;
}