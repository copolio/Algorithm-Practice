//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//int r, c, k, curTime = 0;
//vector<vector<int>> numArray;
//
//bool cmp(pair<int, int> a, pair<int, int> b) {
//	if (a.second != b.second)
//		return a.second < b.second;
//	return a.first < b.first;
//}
//
//void GetInput() {
//	cin >> r >> c >> k;
//	for (int i = 0; i < 3; i++) {
//		vector<int> row;
//		int num;
//		for (int j = 0; j < 3; j++) {
//			cin >> num;
//			row.push_back(num);
//		}
//		numArray.push_back(row);
//	}
//}
//
//void SortRow() {
//	int width = 0;
//	for (int i = 0; i < numArray.size(); i++) {
//		map<int, int> temp1;
//		vector<pair<int, int>> temp2;
//		vector<int> newRow;
//
//		for (int j = 0; j < numArray[i].size(); j++) {
//			if (numArray[i][j] == 0) continue;
//			if (temp1[numArray[i][j]] == NULL) temp1[numArray[i][j]] = 1;
//			else temp1[numArray[i][j]]++;
//		}
//		for (auto n : temp1) {
//			temp2.push_back(make_pair(n.first, n.second));
//		}
//		sort(temp2.begin(), temp2.end(), cmp);
//		for (auto n : temp2) {
//			newRow.push_back(n.first);
//			newRow.push_back(n.second);
//			if (newRow.size() == 100) break;
//		}
//		width = newRow.size() > width ? newRow.size() : width;
//		numArray[i] = newRow;
//	}
//	for (int i = 0; i < numArray.size(); i++) {
//		int nZero = width - numArray[i].size();
//		for (int j = 0; j < nZero; j++)
//			numArray[i].push_back(0);
//	}
//}
//
//void SortCol() {
//	int height = 0;
//	for (int i = 0; i < numArray[0].size(); i++) {
//		map<int, int> temp1;
//		vector<pair<int, int>> temp2;
//		vector<int> newCol;
//
//		for (int j = 0; j < numArray.size(); j++) {
//			if (numArray[j][i] == 0) continue;
//			if (temp1[numArray[j][i]] == NULL) temp1[numArray[j][i]] = 1;
//			else temp1[numArray[j][i]]++;
//		}
//		for (auto n : temp1)
//			temp2.push_back(make_pair(n.first, n.second));
//		sort(temp2.begin(), temp2.end(), cmp);
//		for (auto n : temp2) {
//			newCol.push_back(n.first);
//			newCol.push_back(n.second);
//			if (newCol.size() == 100) break;
//		}
//		height = newCol.size() > height ? newCol.size() : height;
//		while (height > numArray.size()) {
//			vector<int> newRow(numArray[0].size(), 0);
//			numArray.push_back(newRow);
//		}
//		for (int j = 0; j < numArray.size(); j++) {
//			numArray[j][i] = 0;
//		}
//		for (int j = 0; j < newCol.size(); j++) {
//			numArray[j][i] = newCol[j];
//		}
//	}
//}
//
//void Solve() {
//	while (true) {
//		if (curTime > 100) {
//			cout << -1;
//			break;
//		}
//		if (numArray.size() >= r && numArray[0].size() >= c && numArray[r - 1][c - 1] == k) {
//			cout << curTime;
//			break;
//		}
//		int nRow = numArray.size();
//		int nCol = numArray[0].size();
//		if (nRow >= nCol)
//			SortRow();
//		else
//			SortCol();
//		curTime++;
//	}
//}
//
//int main() {
//	GetInput();
//	Solve();
//	return 0;
//}