#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
int N;
int numbers[11] = { 0, };
long long maxNumber = -INF;
long long minNumber = INF;
vector<pair<int, long>> operators;

int main() {
	cin >> N;
	operators.push_back(make_pair(0, 0));
	operators.push_back(make_pair(1, 0));
	operators.push_back(make_pair(2, 0));
	operators.push_back(make_pair(3, 0));
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> operators[i].second;
	}
	do {
		long long result = numbers[0];
		int opIndex = 0;
		vector<pair<int, long>> temp = operators;
		for (int i = 1; i < N; i++) {
			while (temp[opIndex].second == 0) {
				opIndex++;
				if (opIndex > 3) break;
			}
			if (opIndex > 3) break;
			switch (temp[opIndex].first) {
			case 0 :
				result += (long long)numbers[i];
				break;
			case 1:
				result -= (long long)numbers[i];
				break;
			case 2:
				result *= (long long)numbers[i];
				break;
			case 3:
				result /= (long long)numbers[i];
				break;
			}
			temp[opIndex].second--;
		}
		minNumber = result < minNumber ? result : minNumber;
		maxNumber = result > maxNumber ? result : maxNumber;
	} while (next_permutation(operators.begin(), operators.end()));
	cout << maxNumber << endl;
	cout << minNumber;
	return 0;
}