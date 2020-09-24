#include<bits/stdc++.h>
using namespace std;

void solve(long long int *arr, int N) {
	stack<long long int> stk;
	long long int *smallPrev = new long long int[N];
	long long int *smallNext = new long long int[N];
	long long int ans = 0;
	for (int i = 0; i < N; i++) {
		if (arr[i] == 0) {
			smallPrev[i] = 0;
			while (!stk.empty()) {
				stk.pop();
			}
			continue;
		}
		smallPrev[i] = 0;
		if (stk.empty()) {
			stk.push(i);
			continue;
		}
		if (arr[stk.top()] < arr[i]) {
			stk.push(i);
		} else {
			int cnt = 0;
			while ((!stk.empty()) && (arr[stk.top()] >= arr[i])) {
				smallPrev[i] += smallPrev[stk.top()] + 1;
				stk.pop();
			}
			stk.push(i);
		}
	}
	while (!stk.empty()) {
		stk.pop();
	}
	for (int i = N - 1; i >= 0; i--) {
		if (arr[i] == 0) {
			smallNext[i] = 0;
			while (!stk.empty()) {
				stk.pop();
			}
			continue;
		}
		smallNext[i] = 0;
		if (stk.empty()) {
			stk.push(i);
			continue;
		}
		if (arr[stk.top()] < arr[i]) {
			stk.push(i);
		} else {
			int cnt = 0;
			while ((!stk.empty()) && (arr[stk.top()] >= arr[i])) {
				smallNext[i] += smallNext[stk.top()] + 1;
				stk.pop();
			}
			stk.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		ans = max(ans, (smallPrev[i] + smallNext[i] + 1) * arr[i]);
	}
	cout << ans << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	while (cin >> N) {
		if (N == 0) {
			break;
		}
		long long int *arr = new long long int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		solve(arr, N);
	}
	return 0;
}