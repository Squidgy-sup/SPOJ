#include<bits/stdc++.h>
using namespace std;
vector<int> multiply(vector<int> input, int n ) {
	vector<int> ans;
	long long carry = 0;
	for (int i = 0; i < input.size(); i++) {
		long long s = input[i] * n + carry;
		ans.push_back(s % 10);
		carry = s / 10;
	}
	while (carry != 0) {
		ans.push_back(carry % 10);
		carry = carry / 10;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<int> v, ans;
		for (int i = 1; i <= n; i++) {
			v.push_back(i);
		}
		ans.push_back(1);
		for (int i = 1; i <= n; i++) {
			ans = multiply(ans, i);
		}
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}
		cout << endl;

	}
	return 0;
}