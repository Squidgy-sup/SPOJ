#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int i = 1;
		for (; i < 10000; i++) {
			long long sum = (i * (i + 1)) / 2;
			if (sum >= n) {
				break;
			}
		}
		long long j = ((i - 1) * i) / 2;
		int k = (i * (i + 1)) / 2;
		if (i % 2 == 0) {
			int num = n - j;
			int den = k - n + 1;
			cout << "TERM " << n << " IS " << num << "/" << den << endl;
		} else {
			int num = k - n + 1;
			int den = n - j;
			cout << "TERM " << n << " IS " << num << "/" << den << endl;
		}

	}
	return 0;
}