#include<bits/stdc++.h>
using namespace std;
bool isValid(int i, int j, int N, int M) {
	if (i < 0 || i >= N || j < 0 || j >= M) {
		return false;
	}
	return true;
}
int dfs(char **arr, int N, int M, int i, int j, vector<vector<int>> &dp) {
	char ch = arr[i][j];
	int ans = 1;
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (isValid(i - 1, j - 1, N, M) && arr[i - 1][j - 1] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i - 1, j - 1, dp));
	}
	if (isValid(i - 1, j, N, M) && arr[i - 1][j] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i - 1, j, dp));
	}
	if (isValid(i - 1, j + 1, N, M) && arr[i - 1][j + 1] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i - 1, j + 1, dp));
	}
	if (isValid(i, j - 1, N, M) && arr[i][j - 1] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i, j - 1, dp));
	}
	if (isValid(i, j + 1, N, M) && arr[i][j + 1] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i, j + 1, dp));
	}
	if (isValid(i + 1, j - 1, N, M) && arr[i + 1][j - 1] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i + 1, j - 1, dp));
	}
	if (isValid(i + 1, j, N, M) && arr[i + 1][j] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i + 1, j, dp));
	}
	if (isValid(i + 1, j + 1, N, M) && arr[i + 1][j + 1] == (ch + 1)) {
		ans = max(ans, 1 + dfs(arr, N, M, i + 1, j + 1, dp));
	}
	dp[i][j] = ans;
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t = 0;
	while (true) {
		t++;
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		char **arr = new char*[N];
		for (int i = 0; i < N; i++) {
			arr[i] = new char[M];
			for (int j = 0; j < M; j++) {
				cin >> arr[i][j];
			}
		}
		vector<vector<int>> dp(N, vector<int>(M, -1));
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[i][j] == 'A') {
					ans = max(ans, dfs(arr, N, M, i, j, dp));
				}
			}
		}
		cout  << "Case " << t << ": " << ans << endl;


	}
	return 0;
}