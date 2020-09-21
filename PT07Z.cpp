#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> &distance, vector<bool> &visited, int level, int node, vector<int> *graph) {
	if (visited[node]) {
		return;
	}
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]]) {
			continue;
		}
		distance[graph[node][i]] = level;
		dfs(distance, visited, level + 1, graph[node][i], graph);
	}
}
void solve(int N, vector<int> *graph) {
	vector<int> distance(N, INT_MIN);
	vector<bool> visited(N, false);
	distance[0] = 0;
	dfs(distance, visited, 1, 0, graph);
	int node, dist = INT_MIN;
	for (int i = 0; i < N; i++) {
		if (distance[i] > dist) {
			dist = distance[i];
			node = i;
		}
	}
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		distance[i] = INT_MIN;
	}
	distance[node] = 0;
	dfs(distance, visited, 1, node, graph);
	sort(distance.begin(), distance.end(), greater<int>());
	cout << distance[0] << endl;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	vector<int> *graph = new vector<int>[N];
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		graph[x - 1].push_back(y - 1);
		graph[y - 1].push_back(x - 1);
	}
	//Run dfs/bfs two times , in the first run find the farthest vertex from vert 1, and the again run dfs from that vertex(farthest) and calculate the longest path.
	solve(N, graph);

	return 0;
}