#include <string>
#include <vector>
#include <iostream>

using namespace std;

void replaceNum(string &s, string key, string value)
{
    auto found = s.find(key);
    while (found != string::npos)
    {
        s.replace(found, key.size(), value);
        found = s.find(key);
    }
}

int solution(string s)
{
    int answer = 0;
    vector<string> keys = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = 0; i < keys.size(); i++)
    {
        replaceNum(s, keys[i], to_string(i));
    }
    answer = stoi(s);
    return answer;
}