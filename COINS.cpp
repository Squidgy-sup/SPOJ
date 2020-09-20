#include<bits/stdc++.h>
using namespace std;

map<int, long long> visited;
long long solve(long long N) {
	if (N <= 6) {
		return N;
	}
	if (visited.find(N) != visited.end()) {
		return visited[N];
	} else {
		visited[N] = max(N, solve(N / 2) + solve(N / 3) + solve(N / 4));
		return visited[N];
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	long long N;
	while (cin >> N) {
		cout << solve(N) << endl;
	}
	return 0;
}