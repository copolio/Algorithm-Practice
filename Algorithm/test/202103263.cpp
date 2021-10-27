#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(pair<long, long> a, pair<long, long> b) {
		if (a.first != b.first)
			return a.first > b.first;
		else
			return a.second > b.second;
	}
};

vector<int> solution(int N, vector<int> coffee_times) {
	vector<int> answer;
	priority_queue<pair<long, long>, vector<pair<long, long>>, cmp> pq;
	long nCustomer = 1, time = 0;
	for (; nCustomer <= N; nCustomer++) {
		pq.push(make_pair(coffee_times[nCustomer - 1], nCustomer));
	}
	while (!pq.empty()) {
		time = pq.top().first;
		while (!pq.empty() && pq.top().first <= time) {
			answer.push_back(pq.top().second);
			pq.pop();
		}
		while (nCustomer <= coffee_times.size() && pq.size() < N) {
			pq.push(make_pair(time + coffee_times[nCustomer - 1], nCustomer));
			nCustomer++;
		}
	}

	return answer;
}