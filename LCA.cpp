#include<bits/stdc++.h>
using namespace std;
void findLevel(vector<int> *graph, int node, int level, vector<int> &L, vector<bool> &visited, vector<int> &T) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	L[node] = level;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]]) {
			continue;
		}
		T[graph[node][i]] = node;
		findLevel(graph, graph[node][i], level + 1, L, visited, T);
	}
}

int findMaxLevel(vector<int> &L, int N) {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, L[i]);
	}
	ans++;
	return ans;
}

void assignParent(int node, int level, int nr, vector<int> &T, vector<bool> &visited, vector<int> &parent, vector<int> *graph) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	if (level < nr) {
		parent[node] = 0;
	} else {
		if (level % nr == 0) {
			parent[node] = T[node];
		} else {
			parent[node] = parent[T[node]];
		}
	}

	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]]) {
			continue;
		}
		assignParent(graph[node][i], level + 1, nr, T, visited, parent, graph);
	}


}
int solve(int x, int y, vector<int> &L, int nr, vector<int> &parent, vector<int> &T) {
	while (parent[x] != parent[y]) {
		if (L[parent[x]] < L[parent[y]]) {
			y = parent[y];
		} else {
			x = parent[x];
		}
	}
	while (x != y) {
		if (L[x] < L[y]) {
			y = T[y];
		} else {
			x = T[x];
		}
	}
	return x;
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
			int x;
			cin >> x;
			for (int j = 0; j < x; j++) {
				int a;
				cin >> a;
				graph[i].push_back(a - 1);
				graph[a - 1].push_back(i);
			}
		}
		int M;
		cin >> M;
		vector<int> L(N, 0);
		vector<int> parent(N, 0);
		vector<bool> visited(N, false);
		vector<int> T(N, 0);

		findLevel(graph, 0, 0, L, visited, T);
		int numberOfPartititon = sqrt(findMaxLevel(L, N));
		for (int i = 0; i < N; i++) {
			visited[i] = false;
		}

		assignParent(0, 0, numberOfPartititon, T, visited, parent, graph);
		cout << "Case " << t << ":" << "\n";


		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			cout << solve(a - 1, b - 1, L, numberOfPartititon, parent, T) + 1 << endl;
		}
		t++;
	}
	return 0;
}