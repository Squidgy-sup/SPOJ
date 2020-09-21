#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if ((x % i) == 0) {
			return false;
		}
	}
	return true;
}
bool possible(int a, int b) {
	string str1 = to_string(a);
	string str2 = to_string(b);
	int cnt = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] != str2[i]) {
			cnt++;
		}
	}
	if (cnt > 1) {
		return false;
	}
	return true;
}
void solve(vector<bool> &visited, vector<int> &distance, vector<int> *graph, int node) {
	queue<int> q;
	q.push(node);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		if (visited[node]) {
			continue;
		}
		visited[node] = true;
		for (int i = 0; i < graph[node].size(); i++) {
			if (visited[graph[node][i]]) {
				continue;
			}
			distance[graph[node][i]] = min(distance[graph[node][i]], distance[node] + 1);
			q.push(graph[node][i]);
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	vector<int> primes;
	for (int i = 1000; i <= 9999; i++) {
		if (isPrime(i)) {
			primes.push_back(i);
		}
	}
	vector<int> *graph = new vector<int>[10000];
	for (int i = 0; i < primes.size(); i++) {
		for (int j = i + 1; j < primes.size(); j++) {
			int a, b;
			a = primes[i];
			b = primes[j];
			if (possible(a, b)) {
				graph[a].push_back(b);
				graph[b].push_back(a);
			}
		}
	}
	while (T--) {
		int a, b;
		cin >> a >> b;
		int N = primes.size();
		vector<bool> visited(10000, false);
		vector<int> distance(10000, INT_MAX);
		distance[a] = 0;
		solve(visited, distance, graph, a);
		if (distance[b] == INT_MAX) {
			cout << "Impossible" << endl;
		} else {
			cout << distance[b] << endl;
		}
	}
	return 0;
}