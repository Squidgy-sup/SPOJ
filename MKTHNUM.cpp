#include<bits/stdc++.h>
using namespace std;
void buildSegment(vector<int> *segment, int start, int end, int index, pair<int, int> *arr) {
	if (start == end) {
		segment[index].push_back(arr[start].second);
		return;
	}
	int mid = (start + end) / 2;
	buildSegment(segment, start, mid, 2 * index, arr);
	buildSegment(segment, mid + 1, end, 2 * index + 1, arr);

	merge(segment[2 * index].begin(), segment[2 * index].end(), segment[2 * index + 1].begin(), segment[2 * index + 1].end(), back_inserter(segment[index]));
}
int query(vector<int> *segment, int a, int b, int c, int start, int end, int index) {
	if (start == end) {
		return segment[index][0];
	}

	int total = upper_bound(segment[2 * index].begin(), segment[2 * index].end(), b) - lower_bound(segment[2 * index].begin(), segment[2 * index].end(), a);
	int mid = (start + end) / 2;
	if (total >= c) {
		return query(segment, a, b, c, start, mid, 2 * index);
	} else {
		return query(segment, a, b, c - total, mid + 1, end, 2 * index + 1);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	cin >> N;
	cin >> M;
	pair<int, int> *arr = new pair<int, int>[N];
	int *A = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
		A[i] = arr[i].first;
	}
	sort(arr, arr + N);
	vector<int> *segment = new vector<int>[4 * N + 1];

	buildSegment(segment, 0, N - 1, 1, arr);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		int index = query(segment, a, b, c, 0, N - 1, 1);
		cout << A[index] << endl;
	}

	return 0;
}