#include<bits/stdc++.h>
using namespace std;

void update(int start, int end, int uStart, int uEnd, int val, int *segment, int index) {
	if (uStart <= start && uEnd >= end) {
		segment[index] += val;
		return;
	}
	if (uStart > end || start > uEnd) {
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, uStart, uEnd, val, segment, 2 * index);
	update(mid + 1, end, uStart, uEnd, val, segment, 2 * index + 1);

}
void updateAll(int start, int end, int *segment, int index) {
	if (start == end) {
		return;
	}
	int mid = (start + end) / 2;
	segment[2 * index] += segment[index];
	segment[2 * index + 1] += segment[index];
	updateAll(start, mid, segment, 2 * index);
	updateAll(mid + 1, end, segment, 2 * index + 1);

}

int query(int start, int end, int qStart, int qEnd, int *segment, int index) {
	if (qStart <= start && qEnd >= end) {
		return segment[index];
	}
	if (qStart > end || start > qEnd) {
		return 0;
	}
	int mid = (start + end) / 2;
	return query(mid + 1, end, qStart, qEnd, segment, 2 * index + 1) + query(start, mid, qStart, qEnd, segment, 2 * index);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n, u;
		cin >> n >> u;
		int *segment = new int[4 * n + 1];
		for (int i = 0; i < 4 * n; i++) {
			segment[i] = 0;
		}
		for (int i = 0; i < u; i++) {
			int a, b;
			int x;
			cin >> a >> b >> x;
			update(0, n - 1, a, b, x, segment, 1);
		}
		updateAll(0, n - 1, segment, 1);
		int q;
		cin >> q;
		while (q--) {
			int x;
			cin >> x;
			cout << query(0, n - 1, x, x, segment, 1) << endl;
		}
	}

	return 0;
}