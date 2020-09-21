#include<bits/stdc++.h>
using namespace std;

bool checkAllNine(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '9') {
			return false;
		}
	}
	return true;
}
string convert(string str) {
	int n = str.size();
	int i = n - 1;
	while ((i >= 0) && (str[i] == '9')) {
		str[i] = '0';
		i--;
	}
	int x = str[i] - '0';
	x += 1;
	str[i] = '0' + x;
	return str;

}
void solve(string str) {
	int n = str.size();
	if (n % 2 == 0) {
		string temp = str.substr(0, n / 2);
		if (checkAllNine(temp)) {
			if (!checkAllNine(str)) {
				for (int i = 0; i < n; i++) {
					cout << "9";
				}
				cout << endl;
				return;
			}
			n++;
			string ans[n];
			for (int i = 0; i < n; i++) {
				ans[i] = '0';
			}
			ans[0] = '1';
			ans[n - 1] = '1';
			for (int i = 0; i < n; i++) {
				cout << ans[i];
			}
			cout << endl;
		} else {
			string str1 =  temp + string(temp.rbegin(), temp.rend());
			string temp2 = convert(temp);
			string str2 = temp2 + string(temp2.rbegin(), temp2.rend());

			// long long ans1 = stoi(str1);
			// long long ans2 = stoi(str2);
			// long long ans = stoi(str);
			if (str1 <= str) {
				cout << str2 << endl;
			} else {
				// cout << min(ans1, ans2) << endl;
				if (str1 > str2) {
					cout << str2 << endl;
				} else {
					cout << str1 << endl;
				}
			}
		}

	} else {
		string temp = str.substr(0, n / 2);
		string t = str.substr(0, 1 + (n / 2));
		if (checkAllNine(t)) {
			if (!checkAllNine(str)) {
				for (int i = 0; i < n; i++) {
					cout << "9";
				}
				cout << endl;
				return;
			}
			n++;
			string ans[n];
			for (int i = 0; i < n; i++) {
				ans[i] = '0';
			}
			ans[0] = '1';
			ans[n - 1] = '1';
			for (int i = 0; i < n; i++) {
				cout << ans[i];
			}
			cout << endl;
		} else {
			string str1 =  t + string(temp.rbegin(), temp.rend());
			string temp2 = convert(t);
			string temp3 = temp2.substr(0, temp2.size() - 1);
			string str2 = temp2 + string(temp3.rbegin(), temp3.rend());

			// long long ans1 = stoi(str1);
			// long long ans2 = stoi(str2);
			// long long ans = stoi(str);
			if (str1 <= str) {
				cout << str2 << endl;
			} else {
				if (str1 > str2) {
					cout << str2 << endl;
				} else {
					cout << str1 << endl;
				}
			}
		}

	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	string str;
	cin >> t;
	while (t--) {
		cin >> str;
		solve(str);
	}
	return 0;
}