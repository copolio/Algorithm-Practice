#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    vector<vector<int>> board;
    for (int i = 0; i < rows; i++)
    {
        vector<int> row;
        for (int j = 0; j < columns; j++)
        {
            row.push_back(i * columns + (j + 1));
        }
        board.push_back(row);
    }
    for (auto p : queries)
    {
        int r1 = p[0] - 1, c1 = p[1] - 1, r2 = p[2] - 1, c2 = p[3] - 1;
        int temp = board[r1][c1];
        int num = temp;
        for (int i = r1; i < r2; i++)
        {
            num = min(num, board[i][c1]);
            board[i][c1] = board[i + 1][c1];
        }
        for (int i = c1; i < c2; i++)
        {
            num = min(num, board[r2][i]);
            board[r2][i] = board[r2][i + 1];
        }
        for (int i = r2; i > r1; i--)
        {
            num = min(num, board[i][c2]);
            board[i][c2] = board[i - 1][c2];
        }
        for (int i = c2; i > c1; i--)
        {
            num = min(num, board[r1][i]);
            board[r1][i] = board[r1][i - 1];
        }
        board[r1][c1 + 1] = temp;
        answer.push_back(num);
    }

    return answer;
}