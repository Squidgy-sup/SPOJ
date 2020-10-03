#include<bits/stdc++.h>
using namespace std;
void buildSegment(vector<int> *segment, int start, int end, int index, int *arr) {
	if (start == end) {
		segment[index].push_back(arr[start]);
		return;
	}
	int mid = (start + end) / 2;
	buildSegment(segment, start, mid, 2 * index, arr);
	buildSegment(segment, mid + 1, end, 2 * index + 1, arr);

	for (int i = 0; i < segment[2 * index].size(); i++) {
		segment[index].push_back(segment[2 * index][i]);
	}
	for (int i = 0; i < segment[2 * index + 1].size(); i++) {
		segment[index].push_back(segment[2 * index + 1][i]);
	}
	sort(segment[index].begin(), segment[index].end());
}
int query(vector<int> *segment, int a, int b, int c, int start, int end, int index) {

	if (start > b || end < a) {
		return 0;
	}

	if (start >= a && (end <= b)) {
		if (segment[index].size() <= 0) {
			return 0;
		}
		if (c < segment[index][0]) {
			return segment[index].size();
		}
		if (c >= segment[index][segment[index].size() - 1]) {
			return 0;
		}

		int l = 0, r = segment[index].size() - 1;
		int m;
		while (l < r)
		{
			m = (l + r) / 2;
			if (segment[index][m] <= c)
				l = m + 1;
			else
				r = m;
		}
		m = (l + r) / 2;
		return (segment[index].size() - m);
	}
	int mid = (start + end) / 2;
	int l = query(segment, a, b, c, start, mid, 2 * index);
	int r = query(segment, a, b, c, mid + 1, end, 2 * index + 1);
	return (l + r);
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	vector<int> *segment = new vector<int>[4 * N + 1];

	buildSegment(segment, 0, N - 1, 1, arr);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << query(segment, a - 1, b - 1, c, 0, N - 1, 1) << endl;
	}

	return 0;
}