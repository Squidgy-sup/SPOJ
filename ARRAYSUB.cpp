#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int k;
	cin >> k;
	deque<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		if (q.empty()) {
			q.push_back(make_pair(i, arr[i]));
			if (i >= k - 1) {
				cout << q.front().second << endl;
			}
			continue;
		}
		if (q.front().second <= arr[i]) {
			while (!q.empty()) {
				q.pop_front();
			}
			q.push_back(make_pair(i, arr[i]));
			if (i >= k - 1) {
				cout << q.front().second << endl;
			}
		} else {
			while ((!q.empty()) && (i - q.front().first >= k)) {
				q.pop_front();
			}
			while ((!q.empty()) && arr[i] >= q.back().second) {
				q.pop_back();
			}
			q.push_back(make_pair(i, arr[i]));
			if (i >= k - 1) {
				cout << q.front().second << endl;
			}
		}
	}
	return 0;
}