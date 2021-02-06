//#include <string>
//#include <vector>
//#include <map>
//#include <sstream>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//int solution(int n, vector<string> recipes, vector<string> orders) {
//	int answer = 0, currenttime = 0;
//	map<string, int> recipe;
//	vector<int> stoves(n, 1);
//	for (int i = 0; i < recipes.size(); i++) {
//		vector<string> temp;
//		istringstream iss(recipes[i]);
//		string token;
//		while (getline(iss, token, ' ')) {
//			temp.push_back(token);
//		}
//		recipe[temp[0]] = stoi(temp[1]);
//	}
//
//	while (!orders.empty() || !stoves.empty()) {
//		//for (int i = 0; i < stoves.size(); i++) {
//		//	cout << stoves[i] << " ";
//		//}
//		//cout << endl;
//		currenttime++;
//		//sort(stoves.begin(), stoves.end(), less<int>());
//		for (int i = 0; i < stoves.size(); i++) {
//			stoves[i]--;
//		}
//		if (orders.empty() && stoves.back() == 0)
//			break;
//
//		for (int i = stoves.size() - 1; i >= 0; i--) {
//			if (stoves[i] == 0) stoves.erase(stoves.begin() + i);
//		}
//		//while (!stoves.empty() && stoves.back() <= 0) stoves.pop_back();
//		if (stoves.size() == n) continue;
//		if (!orders.empty()) {
//			string order = orders.front();
//			orders.erase(orders.begin());
//			vector<string> temp;
//			istringstream iss(order);
//			string token;
//			while (getline(iss, token, ' ')) {
//				temp.push_back(token);
//			}
//			if (stoves.size() < n) {
//				if (stoi(temp[1]) > currenttime)
//					stoves.push_back(recipe[temp[0]] + stoi(temp[1]) - currenttime);
//				else {
//					stoves.push_back(recipe[temp[0]]);
//				}
//			}
//		}
//	}
//	answer = currenttime;
//	return answer;
//}
//
//int main() {
//	cout << solution(3, { "SPAGHETTI 3", "FRIEDRICE 2", "PIZZA 8" }, { "PIZZA 1", "FRIEDRICE 2", "SPAGHETTI 4", "SPAGHETTI 6", "PIZZA 7", "SPAGHETTI 8" });
//	return 1;
//}