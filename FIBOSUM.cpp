#include<bits/stdc++.h>
using namespace std;

long long mod = pow(10, 9) + 7;

void multiply(vector<vector<int>> &arr) {
	vector<vector<int>> arr1(2, vector<int>(2, 1));
	arr1[0][0] = ((arr[0][0] % mod * arr[0][0] % mod) % mod + (arr[0][1] % mod * arr[1][0] % mod) % mod) % mod;
	arr1[0][1] = ((arr[0][0] % mod * arr[0][1] % mod) % mod + (arr[0][1] % mod * arr[1][1] % mod) % mod) % mod;
	arr1[1][0] = ((arr[1][0] % mod * arr[0][0] % mod) % mod + (arr[1][1] % mod * arr[1][0] % mod) % mod) % mod;
	arr1[1][1] = ((arr[1][0] % mod * arr[0][1] % mod) % mod + (arr[1][1] % mod * arr[1][1] % mod) % mod) % mod;
	arr[0][0] = arr1[0][0];
	arr[0][1] = arr1[0][1];
	arr[1][0] = arr1[1][0];
	arr[1][1] = arr1[1][1];
}
void fib(int m, vector<vector<int>> &arr) {
	if (m == 0 || m == 1) {
		return;
	}
	fib(m / 2, arr);
	multiply(arr);
	if (m % 2 == 0) {
		return;
	}
	vector<vector<int>> arr1(2, vector<int>(2, 1));
	arr1[0][0] = (arr[0][0] * 1 + arr[0][1] * 1) % mod;
	arr1[0][1] = arr[0][0];
	arr1[1][0] = arr[1][0] + arr[1][1];
	arr1[1][1] = arr[1][0];
	arr[0][0] = arr1[0][0];
	arr[0][1] = arr1[0][1];
	arr[1][0] = arr1[1][0];
	arr[1][1] = arr1[1][1];

}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> arr(2, vector<int>(2, 1));
		arr[1][1] = 0;

		fib(m + 1, arr);

		long long ans1 = arr[0][0] % mod;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				arr[i][j] = 1;
			}
		}
		arr[1][1] = 0;
		fib(n , arr);
		long long ans2 = arr[0][0] % mod;
		long long ans = (ans1 % mod - ans2 % mod + mod) % mod;
		cout << ans << endl;
	}

	return 0;
}