#include<bits/stdc++.h>
using namespace std;
bool isValid(int i, int j, int N, int M) {
	if (i < 0 || i >= N || j < 0 || j >= M) {
		return false;
	}
	return true;
}
void solve(int N, int M, vector<vector<bool>> &visited,	vector<vector<int>> &ans, queue<pair<int, int>> &q) {
	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		if (isValid(i + 1, j, N, M)) {
			if (!visited[i + 1][j]) {
				q.push(make_pair(i + 1, j));
				visited[i + 1][j] = true;
				ans[i + 1][j] = 1 + ans[i][j];
			}
		}
		if (isValid(i - 1, j, N, M)) {
			if (!visited[i - 1][j]) {
				q.push(make_pair(i - 1, j));
				visited[i - 1][j] = true;
				ans[i - 1][j] = 1 + ans[i][j];
			}

		}
		if (isValid(i, j - 1, N, M)) {
			if (!visited[i][j - 1]) {
				q.push(make_pair(i, j - 1));
				visited[i][j - 1] = true;
				ans[i][j - 1] = 1 + ans[i][j];
			}

		}
		if (isValid(i, j + 1, N, M)) {
			if (!visited[i][j + 1]) {
				q.push(make_pair(i, j + 1));
				visited[i][j + 1] = true;
				ans[i][j + 1] = 1 + ans[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<vector<bool>> visited(N, vector<bool>(M, false));
		vector<vector<int>> ans(N, vector<int>(M, INT_MAX));
		queue<pair<int, int>> q;
		for (int i = 0; i < N; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < M; j++) {
				if (str[j] == '1') {
					q.push(make_pair(i, j));
					visited[i][j] = true;
					ans[i][j] = 0;
				}
			}
		}
		solve(N, M, visited, ans, q);

	}
	return 0;
}