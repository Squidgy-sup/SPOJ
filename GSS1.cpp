#include<bits/stdc++.h>
using namespace std;

#define inf 16000000

struct SegmentTree {
	int maxSum, maxPrefixSum, maxSuffixSum, totalSum;
};

void createSegmentTree(SegmentTree *segmentTree, int index, int start, int end, int *arr) {
	if (start == end) {
		segmentTree[index].maxSum = arr[start];
		segmentTree[index].totalSum = arr[start];
		segmentTree[index].maxPrefixSum = arr[start];
		segmentTree[index].maxSuffixSum = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	createSegmentTree(segmentTree, 2 * index, start, mid, arr);
	createSegmentTree(segmentTree, 2 * index + 1, mid + 1, end, arr);
	segmentTree[index].maxSum = max(max(segmentTree[2 * index].maxSum, segmentTree[2 * index + 1].maxSum), segmentTree[2 * index].maxSuffixSum + segmentTree[2 * index + 1].maxPrefixSum);
	segmentTree[index].totalSum = segmentTree[2 * index].totalSum + segmentTree[2 * index + 1].totalSum;
	segmentTree[index].maxPrefixSum = max(segmentTree[2 * index].totalSum + segmentTree[2 * index + 1].maxPrefixSum, segmentTree[2 * index].maxPrefixSum);
	segmentTree[index].maxSuffixSum = max(segmentTree[2 * index + 1].totalSum + segmentTree[2 * index].maxSuffixSum, segmentTree[2 * index + 1].maxSuffixSum);
}

SegmentTree solveQuery(SegmentTree *segmentTree, int start, int end, int qStart, int qEnd, int index) {
	if ((qEnd < start) || (end < qStart)) {
		return { -inf, -inf, -inf, -inf};
	}
	if ((start >= qStart) && (end <= qEnd)) {
		return segmentTree[index];
	}

	int mid = (start + end) / 2;
	SegmentTree leftAns = solveQuery(segmentTree, start, mid, qStart, qEnd, 2 * index);
	SegmentTree rightAns = solveQuery(segmentTree, mid + 1, end, qStart, qEnd, 2 * index + 1);
	SegmentTree ans;
	ans.maxSum = max(max(leftAns.maxSum, rightAns.maxSum), leftAns.maxSuffixSum + rightAns.maxPrefixSum);
	ans.totalSum = leftAns.totalSum + rightAns.totalSum;
	ans.maxPrefixSum = max(leftAns.totalSum + rightAns.maxPrefixSum, leftAns.maxPrefixSum);
	ans.maxSuffixSum = max(rightAns.totalSum + leftAns.maxSuffixSum, rightAns.maxSuffixSum);
	return  ans;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.tie(0);
	int N;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	SegmentTree *segmentTree = new SegmentTree[4 * N];
	createSegmentTree(segmentTree, 1, 0, N - 1, arr);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		SegmentTree ans = solveQuery(segmentTree, 0, N - 1, x - 1, y - 1, 1);
		cout << ans.maxSum << "\n";
	}
	return 0;
}