#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 1e8

using namespace std;

vector<int> dijsktra(int start, vector<vector<int>> graph) {
	priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, less<pair<int, vector<int>>>> pq;
	vector<int> minFare (graph.size(), INF);
	pq.push({ 0, {start} });
	minFare[start] = 0;
	vector<vector<int>> paths(graph.size());

	while (!pq.empty()) {
		int cost = pq.top().first;
		vector<int> path = pq.top().second;
		int now = path.back();
		paths[now] = path;
		pq.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int nextCost = graph[now][i];
			if (minFare[i] > minFare[now] + graph[now][i]) {
				minFare[i] = minFare[now] + graph[now][i];
				vector<int> temp = path;
				temp.push_back(i);
				pq.push({ minFare[i], temp });
			}
		}
	}
	return minFare;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	int answer = INF;
	vector<vector<int>> graph(n+1, vector<int>(n+1, INF));
	for (int i = 0; i < fares.size(); i++) {
		graph[fares[i][0]][fares[i][1]] = fares[i][2];
		graph[fares[i][1]][fares[i][0]] = fares[i][2];
	}
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}
	vector<int> startFares = dijsktra(s, graph);
	vector<int> aFares = dijsktra(a, graph);
	vector<int> bFares = dijsktra(b, graph);
	for (int i = 1; i <= n; i++) {
		int cost = startFares[i] + aFares[i] + bFares[i];
		answer = answer >  cost ? cost : answer; 
	}
	return answer;
}