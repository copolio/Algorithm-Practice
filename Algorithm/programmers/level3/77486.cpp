#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    unordered_map<string, string> tree;
    unordered_map<string, int> sales;

    for (int i = 0; i < enroll.size(); i++)
    {
        tree[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++)
    {
        int profit = amount[i] * 100;
        string cur = seller[i];
        while (cur != "-")
        {
            if (profit * 0.1 < 1)
            {
                sales[cur] += profit;
                break;
            }
            sales[cur] += ceil(profit * 0.9);
            profit *= 0.1;
            cur = tree[cur];
        }
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(sales[enroll[i]]);
    }

    return answer;
}