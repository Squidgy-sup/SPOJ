#include<bits/stdc++.h>
using namespace std;
long long solve(long long *arr, int i, int j, int cnt, vector<vector<long long>> &dp) {
	if (i == j) {
		return cnt * arr[i];
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] = max(cnt * arr[i] + solve(arr, i + 1, j, cnt + 1, dp), cnt * arr[j] + solve(arr, i, j - 1, cnt + 1, dp));
	return dp[i][j];
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	long long *arr = new long long[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<vector<long long>> dp(N, vector<long long>(N, -1));
	cout << solve(arr, 0, N - 1, 1, dp) << endl;
	return 0;
}