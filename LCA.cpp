#include<bits/stdc++.h>
using namespace std;

bool LCA(vector<int> *graph, int x, int node, stack<int> &stk, vector<bool> &visited) {
	if (visited[node]) {
		return false;
	}
	stk.push(node);

	if (node == x) {
		visited[node] = true;
		return true;
	}
	visited[node] = true;

	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]]) {
			continue;
		}
		if (LCA(graph, x, graph[node][i], stk, visited)) {
			return true;
		}
	}
	stk.pop();
	return false;
}

void solve(vector<int> *graph, int x, int y, int N) {
	stack<int> stk, stk1;
	vector<bool> visited(N, false);
	LCA(graph, x, 0, stk, visited);
	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	LCA(graph, y, 0, stk1, visited);
	stack<int> stk2, stk3;
	while (!stk.empty()) {
		stk2.push(stk.top());
		stk.pop();
	}
	while (!stk1.empty()) {
		stk3.push(stk1.top());
		stk1.pop();
	}
	long long ans = 0;
	while ((!stk2.empty()) & (!stk3.empty())) {
		if (stk2.top() != stk3.top()) {
			break;
		}
		ans = stk2.top();
		stk2.pop();
		stk3.pop();
	}
	ans++;
	cout << ans << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int t = 1;
	while (t <= T) {
		int N;
		cin >> N;
		vector<int> *graph = new vector<int>[N];
		for (int i = 0; i < N; i++) {
			int M;
			cin >> M;
			for (int j = 0; j < M; j++) {
				int x;
				cin >> x;
				x--;
				graph[i].push_back(x);
				graph[x].push_back(i);
			}
		}
		int M;
		cin >> M;
		cout << "Case " << t << ":" << endl;
		for (int i = 0; i < M; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			solve(graph, x, y, N);
		}
		t++;
	}
	return 0;
}