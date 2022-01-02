#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string rmInvalidChars(string &a)
{
    string result;
    vector<char> allowed = {'-', '_', '.'};
    for (auto c : a)
    {
        if (!isalnum(c) && find(allowed.begin(), allowed.end(), c) == allowed.end())
        {
            continue;
        }
        result.push_back(c);
    }

    return result;
}

string joinPeriod(string &a)
{
    string result;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '.')
        {
            int last = i;
            while (last < a.size() && a[last] == '.')
            {
                last++;
            }
            i = last - 1;
            result.push_back('.');
        }
        else
        {
            result.push_back(a[i]);
        }
    }
    return result;
}

string rmPeriod(string &a)
{
    if (a.front() == '.')
    {
        a.erase(a.begin());
    }

    if (a.back() == '.')
    {
        a.erase(a.end() - 1);
    }

    return a;
}

string solution(string new_id)
{
    string answer = new_id;
    for_each(answer.begin(), answer.end(), [](char &c)
             { c = tolower(c); });
    answer = rmInvalidChars(answer);
    answer = joinPeriod(answer);
    answer = rmPeriod(answer);
    if (answer.empty())
    {
        answer = "a";
    }
    if (answer.size() >= 16)
    {
        answer = answer.substr(0, 15);
        if (answer.back() == '.')
        {
            answer.erase(answer.end() - 1);
        }
    }
    while (answer.size() <= 2)
    {
        answer.push_back(answer.back());
    }

    return answer;
}