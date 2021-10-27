#include <string>
#include <vector>
#include <map>

using namespace std;

int arrow[8][2] = { { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } };

int solution(vector<int> arrows) {
	int answer = 0, curY = 0, curX = 0;
	map<pair<int, int>, bool> node_visited;
	map<pair<pair<int, int>, pair<int, int>>, bool> edge_visited;
	node_visited[{0, 0}] = true;
	for (int i = 0; i < arrows.size(); i++) {
		int dir = arrows[i];
		for (int j = 0; j < 2; j++) {
			int nextX = curX + arrow[dir][0];
			int nextY = curY + arrow[dir][1];

			if (node_visited[{nextX, nextY}] == true) {
				if (edge_visited[{ {curX, curY}, { nextX, nextY } }] == false)
					answer++;
			}
			node_visited[{nextX, nextY}] = true;
			edge_visited[{ {curX, curY}, { nextX, nextY } }] = true;
			edge_visited[{ { nextX, nextY }, { curX, curY } }] = true;
			curX = nextX;
			curY = nextY;
		}
	}

	return answer;
}