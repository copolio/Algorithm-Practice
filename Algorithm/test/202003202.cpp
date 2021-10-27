#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<string, string> flagDict;
map<string, string> aliasDict;
map<string, bool> flagUsableDict;
vector<string> flag_argument_types = { "NULL" , "NUMBER" , "NUMBERS" , "STRING" , "STRINGS" };

void SetFlagDict(vector<string> flag_rules) {
	for (string flag_rule : flag_rules) {
		vector<string> temp;
		istringstream ss(flag_rule);
		string buf;
		while (getline(ss, buf, ' ')) {
			temp.push_back(buf);
		}
		if (temp.size() == 2)
			flagDict[temp[0]] = temp[1];
		else {
			flagDict[temp[0]] = temp[2];
			aliasDict[temp[0]] = temp[2];
			aliasDict[temp[2]] = temp[0];
		}
		flagUsableDict[temp[0]] = true;
	}
	for (auto flag_rule : flagDict) {
		if (find(flag_argument_types.begin(), flag_argument_types.end(), flag_rule.second) == flag_argument_types.end()) {
			flagDict[flag_rule.first] = flagDict[flag_rule.second];
		}
	}
}

void ResetFlagUsability() {
	for (auto flag : flagUsableDict) {
		flagUsableDict[flag.first] = true;
	}
}

vector<bool> solution(string program, vector<string> flag_rules, vector<string> commands) {
	vector<bool> answer;
	
	SetFlagDict(flag_rules);
	
	for (string command : commands) {
		ResetFlagUsability();

		queue<string> temp;
		istringstream ss(command);
		string buf;
		while (getline(ss, buf, ' ')) {
			temp.push(buf);
		}
		//프로그램명 오류
		string prog_name = temp.front();
		temp.pop();
		if (prog_name != program) {
			answer.push_back(false);
			continue;
		}

		bool isValid = true;
		while (!temp.empty()) {
			string flag = temp.front();
			temp.pop();
			//대응하는 flag가 없음
			if (flag[0] != '-') {
				isValid = false;
				break;
			}
			//flag를 사용할 수 없음
			if (!flagUsableDict[flag]) {
				isValid = false;
				break;
			}
			string flag_argument_type = flagDict[flag];
			if (aliasDict.find(flag) != aliasDict.end()) {
				flagUsableDict[aliasDict[flag]] = false;
			}

			if (flag_argument_type == "NULL") {
				continue;
			}
			else if (flag_argument_type == "NUMBER") {
				string flag_argument = temp.front();
				temp.pop();
				for (auto c : flag_argument) {
					//숫자가 아님
					if (!isdigit(c)) {
						isValid = false;
						break;
					}
				}
				if (!isValid) break;
			}
			else if (flag_argument_type == "NUMBERS") {
				while (temp.front()[0] != '-') {
					string flag_argument = temp.front();
					temp.pop();
					for (auto c : flag_argument) {
						//숫자가 아님
						if (!isdigit(c)) {
							isValid = false;
							break;
						}
					}
					if (!isValid) break;
				}
				if (!isValid) break;
			}
			else if (flag_argument_type == "STRING") {
				string flag_argument = temp.front();
				temp.pop();
				for (auto c : flag_argument) {
					//문자가 아님
					if (!isalpha(c)) {
						isValid = false;
						break;
					}
				}
				if (!isValid) break;
			}
			else if (flag_argument_type == "STRINGS") {
				while (temp.front()[0] != '-') {
					string flag_argument = temp.front();
					temp.pop();
					for (auto c : flag_argument) {
						//문자가 아님
						if (!isalpha(c)) {
							isValid = false;
							break;
						}
					}
					if (!isValid) break;
				}
				if (!isValid) break;
			}
		}
		answer.push_back(isValid);
	}
	return answer;
}