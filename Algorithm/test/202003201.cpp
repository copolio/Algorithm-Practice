1번
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(vector<string> table, vector<string> languages, vector<int> preference) {
	string answer = "";
	map<pair<string, string>, int> scoreTable;
	vector<string> industries;
	int maxScore = 0;

	for (int i = 0; i < table.size(); i++) {
		vector<string> temp;
		string row = table[i];
		istringstream iss(row);
		string token;
		while (getline(iss, token, ' ')) {
			temp.push_back(token);
		}
		for (int j = 1; j < temp.size(); j++) {
			scoreTable[{temp[0], temp[j]}] = 5 - (j - 1);
		}
		industries.push_back(temp[0]);
	}
	for (int i = 0; i < industries.size(); i++) {
		int score = 0;
		for (int j = 0; j < languages.size(); j++) {
			score += scoreTable[{industries[i], languages[j]}] * preference[j];
		}
		if (score > maxScore) {
			maxScore = score;
			answer = industries[i];
		}
		else if (score == maxScore) {
			answer = answer.compare(industries[i]) < 0 ? answer : industries[i];
		}
	}
	return answer;
}
2번
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<int> charGroup;
map<char, int> chars;

bool CheckRule1(string inp_str) {
	if (inp_str.size() < 8 || inp_str.size() > 15)
		return false;
	return true;
}

bool CheckRule2(string inp_str) {
	string special = "~!@#$%^&*";

	for (int i = 0; i < inp_str.size(); i++) {
		if (chars.find(inp_str[i]) != chars.end())
			chars[inp_str[i]]++;
		else
			chars[inp_str[i]] = 1;
		if (inp_str[i] >= 'A' && inp_str[i] <= 'Z') {
			charGroup.insert(1);
			continue;
		}
		if (inp_str[i] >= 'a' && inp_str[i] <= 'z') {
			charGroup.insert(2);
			continue;
		}
		if (inp_str[i] >= '0' && inp_str[i] <= '9') {
			charGroup.insert(3);
			continue;
		}
		if (special.find(inp_str[i]) != string::npos) {
			charGroup.insert(4);
			continue;
		}
		return false;
	}
	return true;
}

bool CheckRule3(string inp_str) {
	if (charGroup.size() < 3)
		return false;
	return true;
}

bool CheckRule4(string inp_str) {
	int nConsecutive = 1;
	char prevC = inp_str[0];
	for (int i = 1; i < inp_str.size(); i++) {
		if (inp_str[i] == prevC) {
			nConsecutive++;
		}
		else {
			nConsecutive = 1;
			prevC = inp_str[i];
		}
		if (nConsecutive >= 4) return false;
	}
	return true;
}

bool CheckRule5(string inp_str) {
	for (auto c : chars) {
		if (c.second >= 5) return false;
	}
	return true;
}

vector<int> solution(string inp_str) {
	vector<int> answer;
	if (!CheckRule1(inp_str))
		answer.push_back(1);
	if (!CheckRule2(inp_str))
		answer.push_back(2);
	if (!CheckRule3(inp_str))
		answer.push_back(3);
	if (!CheckRule4(inp_str))
		answer.push_back(4);
	if (!CheckRule5(inp_str))
		answer.push_back(5);
	if (answer.empty())
		answer.push_back(0);
	return answer;
}

3번
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
	vector<int> answer;
	// 0 - 초기화, 1- 만났는지 알수 없음, 2 - 반드시 만남
	vector<vector<int>> dp(enter.size() + 1, vector<int>(enter.size() + 1, 0));
	for (int i = 1; i <= enter.size(); i++) {
		int iEnter = find(enter.begin(), enter.end(), i) - enter.begin();
		int iExit = find(leave.begin(), leave.end(), i) - leave.begin();
		for (int j = 1; j <= enter.size(); j++) {
			if (i == j) continue;
			if (dp[i][j] >= 1) continue;
			int jEnter = find(enter.begin(), enter.end(), j) - enter.begin();
			int jExit = find(leave.begin(), leave.end(), j) - leave.begin();
			if (iEnter < jEnter && iExit > jExit) {
				dp[i][j] = 2;
				dp[j][i] = 2;
				for (int k = iEnter + 1; k < jEnter; k++) {
					if (k >= enter.size()) break;
					dp[i][enter[k]] = 2;
					dp[enter[k]][i] = 2;
				}
			}
			else if (iEnter > jEnter && iExit < jExit) {
				dp[i][j] = 2;
				dp[j][i] = 2;
				for (int k = jEnter + 1; k < iEnter; k++) {
					if (k >= enter.size()) break;
					dp[j][enter[k]] = 2;
					dp[enter[k]][j] = 2;
				}
			}
			else {
				dp[i][j] = 1;
				dp[j][i] = 1;
			}
		}
	}
	for (int i = 1; i <= enter.size(); i++) {
		int cnt = count(dp[i].begin(), dp[i].end(), 2);
		answer.push_back(cnt);
	}
	return answer;
}