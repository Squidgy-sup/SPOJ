#include<bits/stdc++.h>
using namespace std;
bool checkbiPartite(int node, int color, vector<bool> &visited, vector<int> *graph, vector < int > &colours) {
	bool ans = true;
	if (visited[node]) {
		return true;
	}
	visited[node] = true;
	colours[node] = color;
	for (int i = 0; i < graph[node].size(); i++) {
		if (visited[graph[node][i]]) {
			if (colours[graph[node][i]] == color) {
				return false;
			}
		}
		ans = ans & (checkbiPartite(graph[node][i], (color == 1) ? 2 : 1, visited, graph, colours));
	}
	return ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	int t = 1;
	while (t <= T) {
		int N, M;
		cin >> N >> M;
		vector<int> *graph = new vector<int>[N];
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		vector<bool> visited(N, false);
		vector<int> colours(N, 0);
		bool ans = true;
		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				continue;
			}
			ans = ans & checkbiPartite(i, 1, visited, graph, colours);
		}
		if (ans) {
			cout << "Scenario #" << t << ":" << endl;
			cout << "No suspicious bugs found!" << endl;
		} else {
			cout << "Scenario #" << t << ":" << endl;
			cout << "Suspicious bugs found!" << endl;
		}
		t++;
	}
	return 0;
}