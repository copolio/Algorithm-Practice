// 65 점 - 원인 아마도 숫자를 바로 스택에 집어넣어서 그런듯.
//#include <cstdlib>
//#include <string>
//#include <vector>
//#include <stack>
//#include <iostream>
//
//using namespace std;
//
//stack<char> operators;
//stack<int> operands;
//
//bool operation() {
//	int num2 = operands.top();
//	operands.pop();
//	int num1 = operands.top();
//	operands.pop();
//	char c = operators.top();
//	operators.pop();
//	int result;
//	if (c == '+')
//		result = num1 + num2;
//	else if (c == '-')
//		result = num1 - num2;
//	else if (c == '*')
//		result = num1 * num2;
//	else if (c == '/') {
//		if (num2 == 0) return false;
//		result = num1 / num2;
//	}
//	operands.push(result);
//	return true;
//}
//
//string solution(string input) {
//	string answer = "";
//	string number = "";
//
//	int temp = 0;
//	for (auto i : input) {
//		if (isdigit(i)) {
//			operands.push(atoi(&i));
//		}
//		else {
//			if (i == '+' || i == '-') {
//				if (operators.empty() || operators.top() == '+' || operators.top() == '-') {
//					operators.push(i);
//				}
//				else {
//					if (!operation()) return "Impossible";
//					operators.push(i);
//				}
//			}
//			else if (i == '*' || i == '/') {
//				if (operators.empty() || operators.top() == '+' || operators.top() == '-') {
//					operators.push(i);
//				}
//				else {
//					if (!operation()) return "Impossible";
//					operators.push(i);
//				}
//			}
//		}
//	}
//	while (!operators.empty()) {
//		if (!operation()) return "Impossible";
//	}
//	answer = to_string(operands.top());
//
//	return answer;
//}