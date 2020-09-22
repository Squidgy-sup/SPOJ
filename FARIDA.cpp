#include<bits/stdc++.h>
using namespace std;

void solve(int N, long long *arr, int t) {

	vector<long long> dp(N, 0);
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		dp[i] = arr[i] + max((i >= 2) ? dp[i - 2] : 0, i >= 3 ? dp[i - 3] : 0);
		dp[i] = max(dp[i], (i >= 1) ? dp[i - 1] : 0);
		ans = max(ans, dp[i]);
	}

	cout << "Case " << t << ": " << ans << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int t = 1;
	while (t <= T) {
		int N;
		cin >> N;
		long long *arr = new long long[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		solve(N, arr, t);
		t++;

	}

	return 0;
}