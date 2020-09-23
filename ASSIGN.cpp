#include<bits/stdc++.h>
using namespace std;
long long solve(int **arr, int i, long long mask, int N, vector<vector<long long>> &dp) {
	if (N == i) {
		if (mask == ((1 << N) - 1))
			return 1;
		return 0;
	}
	if (dp[i][mask] != -1) {
		return dp[i][mask];
	}
	long long ans = 0;
	for (int j = 0; j < N; j++) {
		if (arr[i][j] == 1) {
			if (((1 << j)&mask) == 0) {
				ans += solve(arr, i + 1, mask | (1 << j) , N, dp);
			}
		}
	}
	dp[i][mask] = ans;
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int **arr = new int*[N];
		for (int i = 0; i < N; i++) {
			arr[i] = new int[N];
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		long long mask = 0;
		vector<vector<long long>> dp(N, vector<long long>(1 << N, -1));

		cout << solve(arr, 0, 0, N, dp) << endl;
	}
	return 0;
}