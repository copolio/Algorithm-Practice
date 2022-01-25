#define RANGE 10000000001
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct info
{
    long long y, x;
};
vector<info> v;
long long len, maxX, minX, maxY, minY;
void init()
{
    maxX = -RANGE;
    maxY = -RANGE;
    minX = RANGE;
    minY = RANGE;
}

vector<string> solution(vector<vector<int>> line)
{
    vector<string> answer;
    len = line.size();
    init();
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
        {
            long long adbc = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            if (adbc == 0)
                continue; //평행 또는 일치. 단, 무수히 많은 교점->일치가 주어지지 않는다고 했으니 평행만 있다
            long long bfed = (long long)line[i][1] * line[j][2] - (long long)line[i][2] * line[j][1];
            long long ecaf = (long long)line[i][2] * line[j][0] - (long long)line[i][0] * line[j][2];
            if ((bfed % adbc != 0) || (ecaf % adbc != 0))
                continue; //정수가 아닌 경우
            bfed /= adbc; // x
            ecaf /= adbc; // y
            v.push_back({ecaf, bfed});
            maxX = max(maxX, (long long)bfed);
            maxY = max(maxY, (long long)ecaf);
            minX = min(minX, (long long)bfed);
            minY = min(minY, (long long)ecaf);
        }
    long long row = maxY - minY + 1;
    long long col = maxX - minX + 1;
    string temp(col, '.');
    answer.assign(row, temp);
    for (int i = 0; i < v.size(); i++)
    {
        long long y = v[i].y;
        long long x = v[i].x;
        answer[maxY - y][x - minX] = '*';
    }
    return answer;
}