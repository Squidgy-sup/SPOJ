#include<bits/stdc++.h>
using namespace std;

#define inf  500000001

struct Segment {
	long long maxSum, totalSum, prefixSum, suffixSum;
};

void create(Segment *segmentTree, int *arr, int start, int end, int index) {
	if (start == end) {
		segmentTree[index] = {arr[start], arr[start], arr[start], arr[start]};
		return;
	}
	int mid = (start + end) / 2;
	create(segmentTree, arr, start, mid, 2 * index);
	create(segmentTree, arr, mid + 1, end, 2 * index + 1);
	Segment x = segmentTree[2 * index];
	Segment y = segmentTree[2 * index + 1];
	Segment z;
	z.totalSum = x.totalSum + y.totalSum;
	z.prefixSum = max(x.prefixSum, x.totalSum + y.prefixSum);
	z.suffixSum = max(y.suffixSum, y.totalSum + x.suffixSum);
	z.maxSum = max(x.suffixSum + y.prefixSum, max(x.maxSum, y.maxSum));
	segmentTree[index] = z;
}
void update(Segment *segmentTree, int uStart, int val, int start, int end, int index) {
	if (uStart < start || uStart > end) {
		return;
	}
	if ((uStart == start) && (uStart == end)) {
		segmentTree[index] = {val, val, val, val};
		return;
	}
	int mid = (start + end) / 2;
	update(segmentTree, uStart, val, start, mid, 2 * index);
	update(segmentTree, uStart, val, mid + 1, end, 2 * index + 1);
	Segment x = segmentTree[2 * index];
	Segment y = segmentTree[2 * index + 1];
	Segment z;
	z.totalSum = x.totalSum + y.totalSum;
	z.prefixSum = max(x.prefixSum, x.totalSum + y.prefixSum);
	z.suffixSum = max(y.suffixSum, y.totalSum + x.suffixSum);
	z.maxSum = max(x.suffixSum + y.prefixSum, max(x.maxSum, y.maxSum));
	segmentTree[index] = z;
}
Segment query(Segment *segmentTree, int qStart, int qEnd, int start, int end, int index) {
	if (qStart > end || qEnd < start) {
		return { -inf, -inf, -inf, -inf};
	}
	if (qStart <= start && (end <= qEnd)) {
		return segmentTree[index];
	}
	int mid = (start + end) / 2;
	Segment x = query(segmentTree, qStart, qEnd, start, mid, 2 * index);
	Segment y = query(segmentTree, qStart, qEnd, mid + 1, end, 2 * index + 1);
	Segment z;
	z.totalSum = x.totalSum + y.totalSum;
	z.prefixSum = max(x.prefixSum, x.totalSum + y.prefixSum);
	z.suffixSum = max(y.suffixSum, y.totalSum + x.suffixSum);
	z.maxSum = max(x.suffixSum + y.prefixSum, max(x.maxSum, y.maxSum));
	return z;

}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int M;
	cin >> M;
	Segment *segmentTree = new Segment[4 * N + 1];
	create(segmentTree, arr, 0, N - 1, 1);
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		if (x == 0) {
			int i, val;
			cin >> i >> val;
			i--;
			update(segmentTree, i, val, 0, N - 1, 1);
		} else {
			int a, b;
			cin >> a >> b;
			Segment ans = query(segmentTree, a - 1, b - 1, 0, N - 1, 1);
			cout << ans.maxSum << endl;

		}
	}
	return 0;
}