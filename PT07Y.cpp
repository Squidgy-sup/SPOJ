#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> *graph, int node, vector<bool> &visited) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]]) {
			continue;
		}
		dfs(graph, graph[node][i], visited);
	}
}
bool checkConnected(vector<int> *graph, int N) {
	vector<bool> visited(N, false);
	dfs(graph, 0, visited);
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}
bool dfs1(vector<int> *graph, int node, vector<bool> &visited, vector<bool> &recStack) {
	if (!visited[node]) {
		visited[node] = true;
		recStack[node] = true;
		for (int i = 0; i < graph[node].size(); i++) {
			if (visited[graph[node][i]]) {
				if (recStack[graph[node][i]]) {
					return false;
				}
				continue;
			}
			if (!dfs1(graph, graph[node][i], visited, recStack)) {
				return false;
			}
		}
		recStack[node] = false;
		return true;
	} else {
		if (recStack[node]) {
			return false;
		}
		return true;

	}
}
bool containsCycle(vector<int> *graph, int N) {
	vector<bool> visited(N, false);
	vector<bool> recStack(N, false);
	return dfs1(graph, 0, visited, recStack);
}
int main() {
	//Fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, M;
	cin >> N >> M;
	vector<int> *graph = new vector<int>[N];
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		graph[x].push_back(y);
	}
	bool flag1 = checkConnected(graph, N);
	bool flag2 = containsCycle(graph, N);
	if (flag1 && flag2) {
		cout << "YES";
	} else {

		cout << "NO";
	}
	return 0;
}