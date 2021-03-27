//#include <string>
//#include <vector>
//#include <set>
//#include <algorithm>
//#include <iostream>
//
//using namespace std;
//
//bool isGood(string &s) {
//	for (int i = 0; i < s.size(); i++) {
//		if (count(s.begin(), s.end(), s[i]) > 1)
//			return false;
//	}
//	return true;
//}
//
//int solution(string s) {
//	int answer = 0;
//	set<string> subsets;
//	int len = s.size();
//	for (int i = 0; i < len; i++) {
//		for (int j = 1; j <= len - i; j++) {
//			string sub_string = s.substr(i, j);
//			if (subsets.find(sub_string) != subsets.end()) continue;
//			if (isGood(sub_string)) {
//				subsets.insert(sub_string);
//			}
//		}
//	}
//	answer = subsets.size();
//	return answer;
//}