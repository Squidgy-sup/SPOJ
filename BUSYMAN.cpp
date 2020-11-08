#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p2.second == p1.second) {
		return (p2.first > p1.first);
	}
	return (p2.second > p1.second);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> input;
		for (int i = 0; i < N; i++) {
			pair<int, int> temp;
			cin >> temp.first >> temp.second;
			input.push_back(temp);
		}

		sort(input.begin(), input.end(), compare);

		int ans = 1;
		int last = input[0].second;
		for (int i = 1; i < N; i++) {
			if (last <= input[i].first) {
				last = input[i].second;
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}