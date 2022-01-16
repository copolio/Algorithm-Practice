#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

int getTime(string time)
{
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);
    return (stoi(hour) * 60 + stoi(min));
}

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, int> usage;
    map<string, string> lastIn;
    map<string, bool> isOut;
    for (auto record : records)
    {
        string time = record.substr(0, 5);
        string car = record.substr(6, 4);
        string type = record.substr(11);

        if (type == "IN")
        {
            lastIn[car] = time;
            isOut[car] = false;
        }
        else
        {
            int outTime = getTime(time);
            int inTime = getTime(lastIn[car]);
            if (usage.count(car))
            {
                usage[car] += outTime - inTime;
            }
            else
            {
                usage[car] = outTime - inTime;
            }
            isOut[car] = true;
        }
    }

    for (auto out : isOut)
    {
        if (!out.second)
        {
            string car = out.first;
            int outTime = getTime("23:59");
            int inTime = getTime(lastIn[car]);
            if (usage.count(car))
            {
                usage[car] += outTime - inTime;
            }
            else
            {
                usage[car] = outTime - inTime;
            }
        }
    }

    for (auto usg : usage)
    {
        int time = usg.second;
        if (time > fees[0])
        {
            answer.push_back(fees[1] + ceil((time - fees[0]) / (float)fees[2]) * fees[3]);
        }
        else
        {
            answer.push_back(fees[1]);
        }
    }

    return answer;
}