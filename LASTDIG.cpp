#include<bits/stdc++.h>
using namespace std;
using namespace std;

int power(int x, unsigned int y, int p)
{
	int res = 1;

	x = x % p;

	if (x == 0) return 0;

	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		long long N, K;
		cin >> N >> K;
		if (K == 0) {
			cout << 1 << endl;
			continue;
		}

		cout << power(N, K, 10) << endl;

	}
	return 0;
}