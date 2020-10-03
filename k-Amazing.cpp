#include<bits/stdc++.h>
using namespace std;
void solve(int *arr, int N) {
	int k = N / 2;
	int l = 0, r = N;
	while (l < r) {
		int mid = (l + r) / 2;
		if (possible(mid, arr)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	l--;

}
int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int *arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		solve(arr, N);
	}
	return 0;
}