#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	unordered_map<long long, long long> m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				m[arr[i]*arr[j] + arr[k]]++;
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (arr[k] == 0) {
					continue;
				}
				long long c = ( arr[i] + arr[j] ) * arr[k];
				ans += m[c];
			}
		}
	}
	cout << ans;

}