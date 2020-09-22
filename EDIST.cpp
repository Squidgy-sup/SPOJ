#include<bits/stdc++.h>
using namespace std;
void solve(string str1, string str2, int N, int M) {
	vector<vector<int>> dp(N + 1, vector<int>(M + 1, INT_MAX));
	for (int i = 1; i <= N; i++) {
		dp[i][0] = i;
	}
	for (int i = 1; i <= M; i++) {
		dp[0][i] = i;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
			} else {
				dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j]);
			}
		}
	}
	cout << dp[N][M] << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		string str1, str2;
		cin >> str1 >> str2;
		int N = str1.size();
		int M = str2.size();
		solve(str1, str2, N, M);
	}
	return 0;
}