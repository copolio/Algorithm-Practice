#include <string>
#include <vector>

using namespace std;

int countDivisor(int num)
{
    int nDivisor = 0;

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            nDivisor++;
            if (i != num / i)
                nDivisor++;
        }
    }

    return nDivisor;
}

int solution(int left, int right)
{
    int answer = 0;
    for (int i = left; i <= right; i++)
    {
        int nDivisor = countDivisor(i);
        int num = nDivisor % 2 == 0 ? i : (-1) * i;
        answer += num;
    }
    return answer;
}