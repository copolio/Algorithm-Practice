//#define INF 1e9
//
//int moveDir[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };
//int minDist = INF;
//
//struct Node {
//	int x, y;
//	Node(int _x, int _y) {
//		x = _x;
//		y = _y;
//	}
//	bool operator== (const Node &c) const {
//		return (x == c.x && y == c.y);
//	}
//	bool operator< (const Node &c) const {
//		if (x != c.x)
//			return x < c.x;
//		return y < c.y;
//	}
//};
//
//int BFS(Node start, Node goal, vector<vector<int>> &maze) {
//	int mazeX = maze.size();
//	int mazeY = maze[0].size();
//
//	vector<vector<bool>> visited(mazeX, vector<bool>(mazeY, false));
//	queue<pair<int, Node>> q;
//
//	q.push(make_pair(0, start));
//	visited[start.x][start.y] = true;
//
//	if (start == goal) return 0;
//
//	while (!q.empty()) {
//		int dist = q.front().first + 1;
//		Node curNode = q.front().second;
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nX = curNode.x + moveDir[i][0];
//			int nY = curNode.y + moveDir[i][1];
//
//			if (nX < 0 || nX >= mazeX || nY < 0 || nY >= mazeY) continue;
//			if (visited[nX][nY]) continue;
//			if (nX == goal.x && nY == goal.y) return dist;
//			if (maze[nX][nY] == 2) {
//				visited[nX][nY] = true;
//				continue;
//			}
//			if (maze[nX][nY] == 1) continue;
//			q.push({ dist, Node(nX, nY) });
//			visited[nX][nY] = true;
//		}
//	}
//	return INF;
//}
//
//bool hasVisitedAllNodes(vector<bool> visited) {
//	for (int i = 0; i < visited.size(); i++) {
//		if (!visited[i]) {
//			return false;
//		}
//	}
//	return true;
//}
//
//void DFS(int cur, int dest, int moveDist, vector<vector<int>> &graph, vector<bool> &visited) {
//	if (cur == dest) {
//		if (hasVisitedAllNodes(visited)) {
//			minDist = moveDist < minDist ? moveDist : minDist;
//		}
//		return;
//	}
//
//	int nNeighbor = 0;
//	bool isDeadend = true;
//	for (int i = 0; i < graph.size(); i++) {
//		if (graph[cur][i] < INF) {
//			nNeighbor++;
//			if (visited[i]) continue;
//			isDeadend = false;
//			visited[i] = true;
//			DFS(i, dest, moveDist + graph[cur][i], graph, visited);
//			visited[i] = false;
//		}
//	}
//	if (isDeadend && nNeighbor == 2) {
//		for (int i = 0; i < graph.size(); i++) {
//			if (i == cur) continue;
//			if (graph[cur][i] < INF) {
//				DFS(i, dest, moveDist + graph[cur][i], graph, visited);
//			}
//		}
//	}
//}
//
//int minMoves(vector<vector<int>> maze, int x, int y) {
//	int mazeWidth = maze[0].size();
//	int mazeHeight = maze.size();
//
//	vector<Node> nodes;
//	vector<vector<int>> graph;
//	vector<bool> visited;
//
//	Node startNode = Node(0, 0);
//	Node endNode = Node(x, y);
//
//	nodes.push_back(startNode);
//	for (int i = 0; i < maze.size(); i++) {
//		for (int j = 0; j < maze[i].size(); j++) {
//			if (maze[i][j] == 2) {
//				Node coin = Node(i, j);
//				nodes.push_back(coin);
//			}
//		}
//	}
//	nodes.push_back(endNode);
//
//	graph.resize(nodes.size(), vector<int>(nodes.size(), INF));
//	visited.resize(nodes.size(), false);
//	visited[0] = true;
//
//	for (int i = 0; i < nodes.size(); i++) {
//		for (int j = 0; j < nodes.size(); j++) {
//			if (graph[i][j] < INF) continue;
//			int dist = BFS(nodes[i], nodes[j], maze);
//			if (dist < graph[i][j]) {
//				graph[i][j] = dist;
//				graph[j][i] = dist;
//			}
//		}
//	}
//
//	DFS(0, nodes.size() - 1, 0, graph, visited);
//
//	if (minDist == INF) return -1;
//	return minDist;
//}