#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0;
    bool visited[10] = {
        false,
    };
    for (auto num : numbers)
    {
        visited[num] = true;
    }
    for (int i = 1; i < 10; i++)
    {
        if (!visited[i])
            answer += i;
    }
    return answer;
}