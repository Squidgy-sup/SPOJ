#include<bits/stdc++.h>
using namespace std;
void solve(string str, int N, vector<vector<int>> &dp) {
	for (int j = 1; j < N; j++) {
		for (int k = 0; k < N - j; k++) {
			if (str[k] == str[k + j]) {
				dp[k][k + j] = dp[k + 1][k + j - 1];
			} else {
				dp[k][k + j] = 1 + min(dp[k + 1][k + j], dp[k][k + j - 1]);
			}
		}
	}
	cout << dp[0][N - 1] << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		int N = str.size();
		vector<vector<int>> dp(N, vector<int>(N, 0));
		solve(str, N, dp);
	}
	return 0;
}