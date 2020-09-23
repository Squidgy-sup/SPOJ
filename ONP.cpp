#include<bits/stdc++.h>
using namespace std;
bool isOperand(char ch) {
	if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
		return false;
	}
	return true;
}
bool checkOrder(char ch1, char ch2) {
	if (ch2 == '(') {
		return true;
	}
	if (ch1 == '^') {
		return true;
	}
	if (ch1 == '/') {
		if (ch2 == '^') {
			return false;
		}
		return true;
	}
	if (ch1 == '*') {
		if (ch2 == '^' || ch2 == '/') {
			return false;
		}
		return true;
	}
	if (ch1 == '-') {
		if (ch2 == '^' || ch2 == '/' || ch2 == '*') {
			return false;
		}
		return true;
	}
	if (ch2 == '^' || ch2 == '/' || ch2 == '*' || ch2 == '-') {
		if (ch2 == '^') {
			return false;
		}
		return true;
	}
	return true;
}
void solve(string str) {
	string outputString;
	stack<char> stk;
	for (int i = 0; i < str.size(); i++) {
		if (isOperand(str[i])) {
			outputString.append(1, str[i]);
			continue;
		}
		if (stk.empty() || str[i] == '(') {
			stk.push(str[i]);
			continue;
		}

		if (str[i] == ')') {
			while (stk.top() != '(') {
				outputString.append(1, stk.top());
				stk.pop();
			}
			stk.pop();
			continue;
		}

		char temp = stk.top();
		bool isCurrentHigher = checkOrder(str[i], temp);
		if (isCurrentHigher) {
			stk.push(str[i]);
			continue;
		}
		while ((!stk.empty()) && (!checkOrder(str[i], stk.top()))) {
			outputString.append(1, stk.top());
			stk.pop();
		}
		stk.push(str[i]);
	}
	while (!stk.empty()) {
		outputString.append(1, stk.top());
		stk.pop();
	}
	cout << outputString << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		solve(str);
	}
	return 0;
}