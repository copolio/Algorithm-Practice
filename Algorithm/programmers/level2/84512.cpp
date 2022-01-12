#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string word)
{
    int answer = word.size();
    vector<int> multiplier(5);
    string chars = "AEIOU";
    multiplier[4] = 1;
    for (int i = 1; i < 5; i++)
    {
        multiplier[4 - i] = multiplier[4 - i + 1] * 5 + 1;
    }
    for (int i = 0; i < word.size(); i++)
    {
        answer += chars.find(word.at(i)) * multiplier[i];
    }
    return answer;
}