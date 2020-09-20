#include<bits/stdc++.h>
using namespace std;

void solve(string str) {
	int n = str.size();
	vector<int> ans(n, 0);
	ans[n - 1] = 1;
	if (str[n - 1] == '0') {
		ans[n - 1] = 0;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (str[i + 1] == '0') {
			if ((i + 1) == (n - 1)) {
				ans[i] = 1;
				continue;
			} else {
				ans[i] = ans[i + 2];
			}
		}
		if (str[i] == '0') {
			ans[i] = 0;
			continue;
		}
		ans[i] = ans[i + 1];
		if (str[i] == '1') {
			if (i == n - 2) {
				ans[i]++;
			} else {
				ans[i] += ans[i + 2];
			}
		} else if (str[i] == '2') {
			int x = str[i + 1] - '0';
			if (x <= 6) {
				if (i == n - 2) {
					ans[i]++;
				} else {
					ans[i] += ans[i + 2];
				}
			}
		}
	}
	cout << ans[0] << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (true) {
		string str;
		cin >> str;
		if (str == "0") {
			break;
		}
		solve(str);
	}
	return 0;
}