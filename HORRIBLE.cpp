#include<bits/stdc++.h>
using namespace std;

// void update(vector<long long> &BITS, int start, long long val, int n) {
// 	int index = start + 1;
// 	while (index <= n) {
// 		BITS[index] += val;
// 		index = index + (index & (-index));
// 	}
// }
// long long query(vector<long long> &BITS, int start) {
// 	int index = start + 1;
// 	long long ans = 0;
// 	while (index > 0) {
// 		ans += BITS[index];
// 		index = index - (index & (-index));
// 	}
// 	return ans;
// }
// int main() {
// //Fast IO
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// 	int T;
// 	cin >> T;
// 	while (T--) {
// 		int N;
// 		cin >> N;
// 		vector<long long> BITS(N + 1, 0);
// 		int M;
// 		cin >> M;
// 		for (int i = 0; i < M; i++) {
// 			int q;
// 			cin >> q;
// 			if (q == 0) {
// 				int start, end;
// 				long long val;
// 				cin >> start >> end >> val;
// 				start--;
// 				end--;
// 				for (int j = start; j <= end; j++)
// 					update(BITS, j, val, N);
// 			} else {
// 				int start, end;
// 				cin >> start >> end;
// 				start--; end--;
// 				long long ans = query(BITS, end) - query(BITS, start - 1);
// 				cout << ans << endl;
// 			}
// 		}
// 	}
// 	return 0;
// }

void update(vector<long long> &lazy, vector<long long> &segment, int start, int end, int uStart, int uEnd, long long val, int index) {
	if (lazy[index] != 0) {
		segment[index] += (end - start + 1) * lazy[index];
		lazy[2 * index] += lazy[index];
		lazy[2 * index + 1] += lazy[index];
		lazy[index] = 0;
	}
	if (start > uEnd || end < uStart) {
		return;
	}
	if (start >= uStart && end <= uEnd) {
		segment[index] += val * (end - start + 1);
		lazy[2 * index] += val;
		lazy[2 * index + 1] += val;
		return;
	}

	int mid = (start + end) / 2;
	update(lazy, segment, start, mid, uStart, uEnd, val, 2 * index);
	update(lazy, segment, mid + 1, end, uStart, uEnd, val, 2 * index + 1);
	segment[index] = segment[2 * index] + segment[2 * index + 1];
}
long long query(vector<long long> &lazy, vector<long long> &segment, int start, int end, int uStart, int uEnd, int index) {
	if (lazy[index] != 0) {
		segment[index] += (end - start + 1) * lazy[index];
		lazy[2 * index] += lazy[index];
		lazy[2 * index + 1] += lazy[index];
		lazy[index] = 0;
	}
	if (start > uEnd || end < uStart) {
		return 0;
	}
	if (start >= uStart && end <= uEnd) {
		return segment[index];
	}

	int mid = (start + end) / 2;
	long long ans1 = query(lazy, segment, start, mid, uStart, uEnd, 2 * index);
	long long ans2 = query(lazy, segment, mid + 1, end, uStart, uEnd, 2 * index + 1);
	return ans1 + ans2;

}
int main() {
	//Fast IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<long long> segment(800004, 0);
		vector<long long> lazy(800004, 0);
		for (int i = 0; i < M; i++) {
			int x;
			cin >> x;
			if (x == 0) {
				int l, r;
				long long val;
				cin >> l >> r >> val;
				l--; r--;
				update(lazy, segment, 0, N - 1, l, r, val, 1);
			} else {
				int l,  r;
				cin >> l >> r;
				l--; r--;
				cout << query(lazy, segment, 0, N - 1, l, r, 1) << "\n";
			}
		}
	}
	return 0;
}