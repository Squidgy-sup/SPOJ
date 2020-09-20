#include<bits/stdc++.h>
using namespace std;

bool solutionExist(int N, int C, int *arr, int ans) {
	int cnt = 1;
	int last = arr[0];
	for (int i = 1; i < N; i++) {
		if (arr[i] - last >= ans) {
			cnt++;
			last = arr[i];
		}
	}
	if (cnt >= C) {
		return true;
	}
	return false;

}
void solve(int N, int C, int *arr) {
	sort(arr, arr + N);
	int low = 0;
	int high = arr[N - 1] - arr[0];
	//We are making a binary search on answer
	int ans = (high - low) / 2;
	//We are not making comparison when low is equal to high, an extra check can be applied after the while loop
	while (low < high) {
		ans = (high + low) / 2;
		if (solutionExist(N, C, arr, ans)) {
			low = ans + 1;
		} else {
			high = ans;
		}
	}
	ans = (low + high) / 2;
	ans--;
	cout << ans << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int N, C;
		cin >> N >> C;
		int *arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		solve(N, C, arr);

	}

	return 0;
}