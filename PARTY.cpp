#include<bits/stdc++.h>
using namespace std;
pair<long long, long long> solve(pair<int, int> *arr, int N, int M, int i, vector<vector<pair<long long, long long>>> &dp) {
	if (i == M) {
		return make_pair(0, 0);
	}
	if ((dp[i][N].first != -1) && (dp[i][N].second != -1)) {
		return dp[i][N];
	}
	pair<long long, long long> ans = solve(arr, N, M, i + 1, dp);
	if (arr[i].first > N) {
		dp[i][N] = ans;
		return ans;
	} else {
		pair<long long, long long> ans1 = solve(arr, N - arr[i].first, M, i + 1, dp);
		ans1.second += arr[i].second;
		if (ans1.second > ans.second) {
			ans = ans1;
			ans.first += arr[i].first;
		} else if (ans1.second == ans.second) {
			ans.first = min(ans.first, ans1.first + arr[i].first);
		}
		dp[i][N] = ans;
		return ans;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (true) {
		int N, M;
		cin >> N >> M;
		if (N == 0 && M == 0) {
			break;
		}
		pair<int, int> *arr = new pair<int, int>[M];
		for (int i = 0; i < M; i++) {
			cin >> arr[i].first;
			cin >> arr[i].second;
		}
		vector<vector<pair<long long, long long>>> dp(M, vector<pair<long long, long long>>(N + 1, make_pair(-1, -1)));

		pair<long long, long long> ans = solve(arr, N, M, 0, dp);
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}