#include<bits/stdc++.h>
using namespace std;
void solve(int N, int *arr) {
	stack<int> stk;
	int current = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] == current) {
			current++;
			while (!stk.empty() && stk.top() == current) {
				stk.pop();
				current++;
			}
		} else {
			stk.push(arr[i]);
		}
	}
	if (stk.size() == 0) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
}
int main() {
	//Fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (true) {
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}
		int *arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		solve(N, arr);
	}
	return 0;
}