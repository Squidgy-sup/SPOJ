#include<bits/stdc++.h>
using namespace std;
int solve(int *arr, int i, int j, vector<vector<int>> &dp) {
	if (i == j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int ans = INT_MAX;
	int prefSum = 0;
	int totalSum = 0;

	for (int k = i; k <= j; k++) {
		totalSum += arr[k];
	}
	for (int k = i; k < j; k++) {
		prefSum += arr[k];
		ans = min(ans, solve(arr, i, k, dp) + solve(arr, k + 1, j, dp) + (prefSum % 100) * ((totalSum - prefSum) % 100));
	}
	dp[i][j] = ans;
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	while (cin >> N) {
		int *arr = new int[N];
		int ans = INT_MAX;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		vector<vector<int>> dp(N, vector<int>(N, -1));
		ans = min(ans, solve(arr, 0, N - 1, dp));

		cout << ans << endl;

	}
	return 0;
}