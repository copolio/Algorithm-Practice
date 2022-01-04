#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int width = 0, height = 0;
    for (auto size : sizes)
    {
        width = max(width, min(size[0], size[1]));
        height = max(height, max(size[0], size[1]));
    }
    return width * height;
}