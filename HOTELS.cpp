#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long N, M;
	cin >> N >> M;
	long long *arr = new long long[N];
	for (long long i = 0; i < N; i++) {
		cin >> arr[i];
	}
	queue<long long> q;
	long long current = 0, ans = 0;
	for (long long i = 0; i < N; i++) {
		if (current + arr[i] > M) {
			while (!q.empty() && (current + arr[i] > M)) {
				long long temp = q.front();
				q.pop();
				current -= temp;
			}
			if (current + arr[i] > M) {
				current = 0;
				continue;
			} else {
				current += arr[i];
				ans = max(ans, current);
				q.push(arr[i]);
			}
		} else {
			current += arr[i];
			ans = max(ans, current);
			q.push(arr[i]);
		}
	}
	cout << ans << endl;

	return 0;
}