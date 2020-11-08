#include<bits/stdc++.h>
using namespace std;
string solve(int n, vector<bool> &visited) {
	queue<pair<string, int>> q;
	q.push({"1", 1});
	while (true) {
		int second = q.front().second;
		if (visited[second]) {
			q.pop();
			continue;
		}
		visited[second] = true;
		if (second % n == 0) {
			return q.front().first;
		}
		second = second % n;
		string first = q.front().first;
		q.pop();
		q.push({first + "0", second * 10});
		q.push({first + "1", second * 10 + 1});
	}
	return "0";
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<bool> visited(100 * n, false);
		cout << solve(n, visited) << endl;
	}
	return 0;
}