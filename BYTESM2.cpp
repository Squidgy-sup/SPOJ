#include<bits/stdc++.h>
using namespace std;
long long solve(long long **arr, int N, int M, int i, int j, vector<vector<long long>> &dp) {
	if (j < 0 || j >= M) {
		return 0;
	}
	if (i == N - 1) {
		return arr[i][j];
	}


	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] = arr[i][j] + max(solve(arr, N, M, i + 1, j, dp), max(solve(arr, N, M, i + 1, j - 1, dp), solve(arr, N, M, i + 1, j + 1, dp)));
	return dp[i][j];
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		long long **arr = new long long*[N];
		for (int i = 0; i < N; i++) {
			arr[i] = new long long[M];
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}
		vector<vector<long long>> dp(N, vector<long long>(M, -1));
		long long ans = 0;
		for (int i = 0; i < M; i++) {
			ans = max(ans, solve(arr, N, M, 0, i, dp));
		}
		cout << ans << endl;
	}
	return 0;
}