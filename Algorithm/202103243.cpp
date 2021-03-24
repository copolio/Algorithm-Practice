////시간초과
////#define INF 1e8
////
////int moveDir[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };
////
////bool hasCoin(vector<vector<int>> maze) {
////	for (int i = 0; i < maze.size(); i++) {
////		for (int j = 0; j < maze[i].size(); j++) {
////			if (maze[i][j] == 2) return true;
////		}
////	}
////	return false;
////}
////
////void DFS(pair<int, int> pos, pair<int, int> goal, int moveDist, int *minDist, vector<vector<int>> &maze, int mazeWidth, int mazeHeight, vector<vector<bool>> visited) {
////	visited[pos.first][pos.second] = true;
////	if (moveDist > *minDist) return;
////	if (pos.first == goal.first && pos.second == goal.second) {
////		cout << moveDist << endl;
////		if (!hasCoin(maze) && moveDist < *minDist) {
////			*minDist = moveDist;
////		}
////		return;
////	}
////
////	for (int i = 0; i < 4; i++) {
////		int nX = pos.first + moveDir[i][0];
////		int nY = pos.second + moveDir[i][1];
////		if (nX < 0 || nX >= mazeWidth || nY < 0 || nY >= mazeHeight)
////			continue;
////		if (maze[nX][nY] == 1) continue;
////		if (!visited[nX][nY]) {
////			int temp = maze[pos.first][pos.second];
////			maze[pos.first][pos.second] = 0;
////			DFS({ nX, nY }, goal, moveDist + 1, minDist, maze, mazeWidth, mazeHeight, visited);
////			maze[pos.first][pos.second] = temp;
////		}
////	}
////}
////
////int minMoves(vector<vector<int>> maze, int x, int y) {
////	int minDist = INF;
////
////	int mazeWidth = maze[0].size();
////	int mazeHeight = maze.size();
////
////	vector<vector<bool>> visited(mazeHeight, vector<bool>(mazeWidth, false));
////	DFS({ 0, 0 }, { x, y }, 0, &minDist, maze, mazeWidth, mazeHeight, visited);
////
////	if (minDist == INF)
////		return -1;
////
////	return minDist;
////}
////
//////오류
//#define INF 1e8
//
//int moveDir[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };
//
//struct Node {
//	int x, y, dist;
//	Node(int _x, int _y, int _dist) {
//		x = _x;
//		y = _y;
//		dist = _dist;
//	}
//	Node(const Node &c) {
//		x = c.x;
//		y = c.y;
//		dist = c.dist;
//	}
//	bool operator<(const Node &c) const {
//		return dist < c.dist;
//	}
//};
//
//int dijkstra(Node start, Node end, vector<vector<int>> &maze) {
//	int mazeX = maze.size();
//	int mazeY = maze[0].size();
//
//	vector<vector<bool>> visited(mazeX, vector<bool>(mazeY, false));
//	priority_queue<Node, vector<Node>, less<Node>> pq;
//	start.dist = 0;
//	pq.push(start);
//
//	while (!pq.empty()) {
//		Node curNode = pq.top();
//		int dist = curNode.dist + 1;
//		visited[curNode.x][curNode.y] = true;
//		pq.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int nX = curNode.x + moveDir[i][0];
//			int nY = curNode.y + moveDir[i][1];
//
//			if (nX < 0 || nX >= mazeX || nY < 0 || nY >= mazeY) continue;
//			if (maze[nX][nY] == 1) continue;
//			if (nX == end.x && nY == end.y) {
//				return dist;
//			}
//			if (!visited[nX][nY]) {
//				pq.push(Node(nX, nY, dist));
//			}
//		}
//	}
//	return -1;
//}
//
//int minMoves(vector<vector<int>> maze, int x, int y) {
//	int minDist = 0;
//	vector<pair<int, Node>> coins;
//	Node curNode = Node(0, 0, 0);
//	Node end = Node(x, y, 0);
//
//	for (int i = 0; i < maze.size(); i++) {
//		for (int j = 0; j < maze[i].size(); j++) {
//			if (maze[i][j] == 2) {
//				Node coin = Node(i, j, 0);
//				int distStart = dijkstra(curNode, coin, maze);
//				int distEnd = dijkstra(coin, end, maze);
//				if (distStart < 0 || distEnd < 0) return -1;
//				coin.dist = distEnd;
//				coins.push_back(make_pair(distStart + distEnd, coin));
//			}
//		}
//	}
//
//	sort(coins.begin(), coins.end(), greater<pair<int, Node>>());
//	while (!coins.empty()) {
//		curNode = coins.back().second;
//		minDist += coins.back().first - curNode.dist;
//		cout << "move " << coins.back().first - curNode.dist << endl;
//
//		coins.pop_back();
//
//		for (int i = 0; i < coins.size(); i++) {
//			coins[i].first = dijkstra(curNode, coins[i].second, maze);
//		}
//		sort(coins.begin(), coins.end(), greater<pair<int, Node>>());
//	}
//	int lastMove = dijkstra(curNode, end, maze);
//	if (lastMove < 0) return -1;
//	minDist += lastMove;
//
//	return minDist;
//}
////
//////  BFS
////
////#define INF 1e8
////
////int moveDir[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };
////
////struct Node {
////	int x, y, dist;
////	Node(int _x, int _y, int _dist) {
////		x = _x;
////		y = _y;
////		dist = _dist;
////	}
////	Node(const Node &c) {
////		x = c.x;
////		y = c.y;
////		dist = c.dist;
////	}
////	bool operator<(const Node &c) const {
////		return dist < c.dist;
////	}
////	bool operator>(const Node &c) const {
////		return dist > c.dist;
////	}
////};
////
////int minMoves(vector<vector<int>> maze, int x, int y) {
////	int minDist = -1;
////	int mazeX = maze.size();
////	int mazeY = maze[0].size();
////
////	set<Node> coins;
////	for (int i = 0; i < mazeX; i++) {
////		for (int j = 0; j < mazeY; j++) {
////			if (maze[i][j] == 2) {
////				coins.insert(Node(i, j, 0));
////			}
////		}
////	}
////
////	vector<vector<bool>> visited(mazeX, vector<bool>(mazeY, false));
////	priority_queue<Node, vector<Node>> pq;
////
////	Node start = Node(0, 0, 0);
////	Node end = Node(x, y, 0);
////
////	start.dist = 0;
////	pq.push(start);
////
////	while (!pq.empty()) {
////		Node curNode = pq.top();
////		pq.pop();
////
////		int dist = curNode.dist + 1;
////		visited[curNode.x][curNode.y] = true;
////		if (maze[curNode.x][curNode.y] == 2) {
////			coins.erase(Node(curNode.x, curNode.y, 0));
////		}
////
////		bool inGoal = false;
////		for (int i = 0; i < 4; i++) {
////			int nX = curNode.x + moveDir[i][0];
////			int nY = curNode.y + moveDir[i][1];
////
////			if (nX < 0 || nX >= mazeX || nY < 0 || nY >= mazeY) continue;
////			if (maze[nX][nY] == 1) continue;
////			if (nX == end.x && nY == end.y) {
////				if (coins.empty()) {
////					minDist = dist;
////					inGoal = true;
////					break;
////				}
////			}
////			if (!visited[nX][nY])
////				pq.push(Node(nX, nY, dist));
////		}
////		if (inGoal) break;
////	}
////
////	return minDist;
////}
//
//
//
//
//
//// 몰라 가장 최근 방법
//int moveDir[4][2] = { {1, 0},{-1, 0},{0, 1},{0, -1} };
//
//struct Node {
//	int x, y;
//	Node(int _x, int _y) {
//		x = _x;
//		y = _y;
//	}
//	bool operator<(const Node &c) const {
//		if (x != c.x)
//			return x < c.x;
//		else
//			return y < c.y;
//	}
//	bool operator==(const Node &c) const {
//		return (x == c.x && y == c.y);
//	}
//};
//
//vector<Node> FindShortestPath(Node start, Node end, vector<vector<int>> &maze) {
//	int mazeX = maze.size();
//	int mazeY = maze[0].size();
//
//	queue<pair<int, vector<Node>>> q;
//	vector<vector<bool>> visited(mazeX, vector<bool>(mazeY, false));
//	q.push({ 0, {start} });
//
//	while (!q.empty()) {
//		pair<int, vector<Node>> curNode = q.front();
//		q.pop();
//
//		int dist = curNode.first + 1;
//
//		vector<Node> path = curNode.second;
//		Node curPos = path.back();
//		visited[curPos.x][curPos.y] = true;
//
//		for (int i = 0; i < 4; i++) {
//			int nX = curPos.x + moveDir[i][0];
//			int nY = curPos.y + moveDir[i][1];
//			if (nX < 0 || nX >= mazeX || nY < 0 || nY >= mazeY) continue;
//			if (maze[nX][nY] == 1) continue;
//			if (nX == end.x && nY == end.y) {
//				vector<Node> temp = path;
//				temp.push_back(Node(nX, nY));
//				return temp;
//			}
//			if (!visited[nX][nY]) {
//				vector<Node> temp = path;
//				temp.push_back(Node(nX, nY));
//				q.push({ dist, temp });
//			}
//		}
//	}
//	return {};
//}
//
//Node FindClosestNode(Node coin, set<Node> &visitedNodes, vector<vector<int>> &maze) {
//	int mazeX = maze.size();
//	int mazeY = maze[0].size();
//
//	queue<pair<int, Node>> q;
//	vector<vector<bool>> visited(mazeX, vector<bool>(mazeY, false));
//	q.push({ 0, coin });
//
//	while (!q.empty()) {
//		pair<int, Node> curNode = q.front();
//		q.pop();
//
//		int dist = curNode.first + 1;
//		Node curPos = curNode.second;
//		visited[curPos.x][curPos.y] = true;
//
//		for (int i = 0; i < 4; i++) {
//			int nX = curPos.x + moveDir[i][0];
//			int nY = curPos.y + moveDir[i][1];
//			if (nX < 0 || nX >= mazeX || nY < 0 || nY >= mazeY) continue;
//			if (maze[nX][nY] == 1) continue;
//			if (!visited[nX][nY]) {
//				Node temp = Node(nX, nY);
//				if (visitedNodes.find(temp) != visitedNodes.end()) {
//					return temp;
//				}
//				q.push({ dist, temp });
//			}
//		}
//	}
//	return coin;
//}
//
//int minMoves(vector<vector<int>> maze, int x, int y) {
//	set<Node> coins;
//	vector<Node> uncollectedCoins;
//
//	int minDist = -1;
//	Node start = Node(0, 0);
//	Node end = Node(x, y);
//
//	map<Node, bool> isCoinCollected;
//
//	for (int i = 0; i < maze.size(); i++) {
//		for (int j = 0; j < maze[i].size(); j++) {
//			if (maze[i][j] == 2) {
//				Node coin = Node(i, j);
//				isCoinCollected[coin] = false;
//				coins.insert(coin);
//			}
//		}
//	}
//
//	vector<Node> mainBranch = FindShortestPath(start, end, maze);
//	set<Node> visitedNodes(mainBranch.begin(), mainBranch.end());
//
//	if (mainBranch.size() == 0) return -1;
//
//	for (int i = 0; i < mainBranch.size(); i++) {
//		minDist++;
//		int curX = mainBranch[i].x;
//		int curY = mainBranch[i].y;
//		if (maze[curX][curY] == 2) {
//			coins.erase(mainBranch[i]);
//		}
//	}
//	for (auto coin : coins) {
//		Node closeNode = FindClosestNode(coin, visitedNodes, maze);
//		if (closeNode == coin) return -1;
//		minDist += FindShortestPath(coin, closeNode, maze).size();
//	}
//	return minDist;
//}