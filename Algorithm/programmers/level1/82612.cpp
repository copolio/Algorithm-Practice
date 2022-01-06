using namespace std;

long long solution(int price, int money, int count)
{
    long answer, cost = 0;

    long i = 1;
    while (i <= count)
    {
        cost += price * i;
        i++;
    }

    return answer = money - cost < 0 ? cost - money : 0;
}