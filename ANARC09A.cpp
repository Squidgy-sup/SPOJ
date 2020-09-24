#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	string str;
	int t = 1;
	while (cin >> str) {
		if (str[0] == '-') {
			break;
		}
		stack<char> stk;
		long long ans = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '{') {
				stk.push(str[i]);
				continue;
			}
			if ((!stk.empty())) {
				stk.pop();
				continue;
			}
			stk.push('{');
			ans++;
		}

		ans += stk.size() / 2;
		cout << t << ". " << ans << endl;
		t++;
	}
	return 0;
}