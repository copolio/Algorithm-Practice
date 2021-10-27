#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> nums, int target) {
	vector<int> answer;
	for (int i = 0; i < nums.size() - 1; i++) {
		int neededVal = target - nums[i];
		auto iter = find(nums.begin(), nums.end(), neededVal);
		if (iter == nums.end()) continue;
		int j = iter - nums.begin();
		if (j != i) {
			answer.push_back(i);
			answer.push_back(j);
			return answer;
		}
	}
	return answer;
}

int main() {
	vector<int> ans =  solution({ 1, 2, 3, 4, 5 }, 11);
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}