#include<bits/stdc++.h>
using namespace std;
struct Query {
	int qNumber, left, right, blockIndex, ans;
};

bool comp(Query q1, Query q2) {
	if (q1.blockIndex != q2.blockIndex) {
		return (q2.blockIndex > q1.blockIndex);
	}
	return (q2.right > q1.right);
}

bool comp1(Query q1, Query q2) {
	return (q2.qNumber > q1.qNumber);
}

int solve(Query query, int ql, int qr, int currentL, int currentR, vector<int> &freq, int *arr, int ans) {
	while (ql < currentL) {
		currentL--;
		freq[arr[currentL]]++;
		if (freq[arr[currentL]] == 1) {
			ans++;
		}
	}
	while (ql > currentL) {
		freq[arr[currentL]]--;
		if (freq[arr[currentL]] == 0) {
			ans--;
		}
		currentL++;
	}
	while (qr < currentR) {
		freq[arr[currentR]]--;
		if (freq[arr[currentR]] == 0) {
			ans--;
		}
		currentR--;
	}
	while (qr > currentR) {
		currentR++;
		freq[arr[currentR]]++;
		if (freq[arr[currentR]] == 1) {
			ans++;
		}
	}

	return ans;
}
int main() {
	//Fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//Divide the array in the blocks of size sqrt(size)
	//Offline programming with query sorted for a given block [(L/sqrt(N)), R]
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int M;
	cin >> M;
	Query *query = new Query[M];
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		query[i].qNumber = i;
		query[i].left = x;
		query[i].right = y;
		query[i].blockIndex = x / sqrt(N);
		query[i].ans = 0;
	}
	sort(query, query + M, comp);
	int l = query[0].left, r = query[0].left;
	vector<int> freq(pow(10, 6) + 1, 0);
	freq[arr[l]]++;
	int cnt = 0;
	int ans = 1;
	for (int i = 0; i < M; i++) {
		ans = solve(query[i], query[i].left, query[i].right, l, r, freq, arr, ans);
		query[i].ans = ans;
		l = query[i].left;
		r = query[i].right;
		// cout << l << " " << r << " " << ans << endl;
	}

	sort(query, query + M, comp1);
	for (int i = 0; i < M; i++) {
		cout << query[i].ans << endl;
	}

	return 0;
}
