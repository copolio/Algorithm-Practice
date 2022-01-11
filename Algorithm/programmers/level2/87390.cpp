#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int n, long long left, long long right)
{
    vector<int> answer;
    for (long i = left; i <= right; i++)
    {
        int y = i % n;
        int x = i / n;
        answer.push_back(max(y + 1, x + 1));
    }
    return answer;
}