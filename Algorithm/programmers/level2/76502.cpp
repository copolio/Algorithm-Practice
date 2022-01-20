#include <string>
#include <vector>

using namespace std;

bool isValid(string s)
{
    vector<char> cStack;

    for (auto c : s)
    {
        if (cStack.empty())
        {
            cStack.push_back(c);
        }
        else
        {
            if (c == ']')
            {
                if (cStack.back() != '[')
                {
                    return false;
                }
                cStack.pop_back();
            }
            else if (c == ')')
            {
                if (cStack.back() != '(')
                {
                    return false;
                }
                cStack.pop_back();
            }
            else if (c == '}')
            {
                if (cStack.back() != '{')
                {
                    return false;
                }
                cStack.pop_back();
            }
            else
            {
                cStack.push_back(c);
            }
        }
    }

    return cStack.empty();
}

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); i++)
    {
        string temp = s.substr(1);
        temp += s[0];
        s = temp;
        if (isValid(s))
            answer++;
    }

    return answer;
}