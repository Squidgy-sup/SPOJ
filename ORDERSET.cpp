#include<bits/stdc++.h>
using namespace std;

void update(int index, int start, int end, int i, int val, vector<int> &segment) {
	if (start == end) {
		segment[index] = val;
		return;
	}
	int mid = (start + end) / 2;
	if (i <= mid) {
		update(2 * index, start, mid, i, val, segment);
	} else {
		update(2 * index + 1, mid + 1, end, i, val, segment);
	}

	segment[index] = segment[2 * index] + segment[2 * index + 1];
}
int query_count(int index, int start, int end, int qL, int qR, vector<int> &segment) {
	if (start > qR || end < qL) {
		return 0;
	}
	if (start >= qL && end <= qR) {
		return segment[index];
	}
	int mid = (start + end) / 2;
	int ans1, ans2;
	ans1 = query_count(2 * index, start, mid, qL, qR, segment);
	ans2 = query_count(2 * index + 1, mid + 1, end, qL, qR, segment);

	return ans1 + ans2;
}

int query_kTh(int index, int start, int end, int k, vector<int> &segment) {
	if (start == end) {
		return end;
	}
	int l = segment[2 * index];
	int mid = (start + end) / 2;
	if (l >= k) {
		return query_kTh(2 * index, start, mid, k, segment);
	} else {
		return query_kTh(2 * index + 1, mid + 1, end, k - l, segment);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<char, int>> query;
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		char a;
		int b;
		cin >> a >> b;
		query.push_back(make_pair(a, b));
		temp.push_back(b);
	}
	sort(temp.begin(), temp.end());
	map<int, int> encode, decode;
	encode[temp[0]] = 0;
	decode[0] = temp[0];
	int n = 1;
	for (int i = 1; i < N; i++) {
		if (temp[i] != temp[i - 1]) {
			encode[temp[i]] = n;
			decode[n] = temp[i];
			n++;
		}
	}

	vector<int> segment(1000000000, 0);

	for (int i = 0; i < N; i++) {
		char q = query[i].first;
		int x = query[i].second;

		if (q == 'I') {
			update(1, 0, n - 1, encode[x], 1, segment);
		} else if (q == 'D') {
			update(1, 0, n - 1, encode[x], 0, segment);
		} else if (q == 'C') {
			cout << query_count(1, 0, n - 1, 0, encode[x] - 1, segment) << "\n";
		} else {
			int k = encode[x];
			if (x > segment[1]) {
				cout << "invalid" << "\n";
			} else {
				int ans = query_kTh(1, 0, n - 1, x, segment);
				cout << decode[ans] << "\n";
			}
		}
	}

	return 0;
}