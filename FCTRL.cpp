#include<bits/stdc++.h>
using namespace std;

long long solve(long long N) {
	long long ans = 0;
	while (N > 0) {
		ans += N / 5;
		N = N / 5;
	}
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		long long N;
		cin >> N;
		cout << solve(N) << endl;
	}

	return 0;
}