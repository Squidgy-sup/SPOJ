#include<bits/stdc++.h>
using namespace std;
long long solve(int N, long long *arr, int start, int end) {
	if (start == end) {
		return 0;
	}
	int mid = (start + end) / 2;
	long long leftAns = solve(N, arr, start, mid);
	long long rightAns = solve(N, arr, mid + 1, end);

	long long ans = leftAns + rightAns;

	sort(arr + start, arr + mid + 1);
	sort(arr + mid + 1, arr + end + 1);

	int i = start, j = mid + 1;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			i++;
		} else {
			ans += mid - i + 1;
			j++;
		}
	}
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
		long long *arr = new long long[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		cout << solve(N, arr, 0, N - 1) << endl;
	}
	return 0;
}