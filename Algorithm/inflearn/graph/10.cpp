#include <iostream>

using namespace std;


int moves[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int answer = 0;
int graph[7][7];
bool visited[7][7];

void dfs(int cur[2]) {
    if (cur[0] == 6 && cur[1] == 6) {
        answer++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nextY = cur[0] + moves[i][0];
        int nextX = cur[1] + moves[i][1];
        int next[2] = {nextY, nextX};

        if (nextY >= 0 && nextY < 7 && nextX >= 0 && nextX < 7) {
            if (graph[nextY][nextX] == 0 && !visited[nextY][nextX]) {
                visited[nextY][nextX] = true;
                dfs(next);
                visited[nextY][nextX] = false;
            }
        }
    }

    return;
}

int main() {
    int cur[2] = {0, 0};
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> graph[i][j];
            visited[i][j] = false;
        }
    }
    visited[0][0] = true;
    dfs(cur);

    cout << answer << endl;

    return 0;
}