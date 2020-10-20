#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;

	int i = 2, j = 2;
	long long ans = N;

	while (i * j <= N) {
		while (i * j <= N) {
			ans++;
			j++;
		}
		i++;
		j = i;
	}
	cout << ans << endl;

	return 0;
}