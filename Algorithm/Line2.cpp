//#include <string>
//#include <vector>
//#include <set>
//#include <iostream>
//#define INF 501;
//
//using namespace std;
//
//bool canIntersect(float a1, float b1, float a2, float b2) {
//	if ((float)(a1*b2 - a2 * b1) == 0) return false;
//	return true;
//}
//
//vector<float> intersection(float a1, float b1, float c1, float a2, float b2, float c2) {
//	float px = (float)(b1*c2 - b2 * c1) / (a1*b2 - a2 * b1);
//	float py = (float)(-1 * a1 / b1) * ((b1*c2 - b2 * c1) / (a1*b2 - a2 * b1)) - (c1 / b1);
//	return { px, py };
//}
//
//vector<string> solution(vector<vector<int>> line) {
//	vector<string> answer;
//	set<vector<float>> intersectionPts;
//	for (int i = 0; i < line.size(); i++) {
//		for (int j = 0; j < line.size(); j++) {
//			if (i == j) continue;
//			if (canIntersect(line[i][0], line[i][1], line[j][0], line[j][1])) {
//				intersectionPts.insert(intersection(line[i][0], line[i][1], line[i][2], line[j][0], line[j][1], line[j][2]));
//			}
//		}
//	}
//	int minX = INF; int maxX = 0; int minY = INF; int maxY = 0;
//	for (auto pt : intersectionPts) {
//		if (pt[0] - int(pt[0]) == 0 && pt[1] - int(pt[1]) == 0) {
//			if (pt[0] < minX) minX = pt[0];
//			if (pt[1] < minY) minY = pt[1];
//			if (pt[0] > maxX) maxX = pt[0];
//			if (pt[1] > maxY) maxX = pt[1];
//		}
//	}
//	int width = maxX - minX > 0 ? maxX - minX : 1;
//	int height = maxY - minY > 0 ? maxY - minY : 1;
//	answer = vector<string>(height * 2 + 1, string(width * 2 - 1, '.'));
//
//	for (auto pt : intersectionPts) {
//		if (pt[0] - int(pt[0]) == 0 && pt[1] - int(pt[1]) == 0) {
//			answer[height - (int)pt[1]][(int)pt[0] + width - 1] = '*';
//		}
//	}
//
//	if (height == 1) {
//		for (int i = 0; i < answer.size(); i++) {
//			if (answer[i].find('*') != string::npos) {
//				vector<string> temp;
//				temp.push_back(answer[i]);
//				answer = temp;
//				break;
//			}
//		}
//	}
//
//	return answer;
//}
//
//int main() {
//	solution({ {2, -1, 4},{-2, -1, 4},{0, -1, 1},{5, -8, -12},{5, 8, 12} });
//	solution({ {1, -1, 0 }, { 2, -1, 0 } });
//	solution({ {0, 1, -1 }, { 1, 0, -1 } , {1, 0, 1} });
//	return 1;
//}