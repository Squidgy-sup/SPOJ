#include<bits/stdc++.h>
using namespace std;

void build(pair<int, int> *segment, int start, int end, int index, string str) {
	if (start == end) {
		segment[index].first = ((str[start] == '(') ? 1 : -1);
		segment[index].second = segment[index].first;
		return;
	}
	int mid = (start + end) / 2;
	build(segment, start, mid, 2 * index, str);
	build(segment, mid + 1, end, 2 * index + 1, str);

	segment[index].first = segment[2 * index].first + segment[2 * index + 1].first;
	segment[index].second = min(segment[2 * index].second, segment[2 * index].first + segment[2 * index + 1].second);
}

void update(pair<int, int> *segment, int start, int end, int index, int uIndex) {
	if (start == end) {
		segment[index].first = -1 * segment[index].first;
		segment[index].second = segment[index].first;
		return;
	}
	int mid = (start + end) / 2;
	if (uIndex <= mid) {
		update(segment, start, mid, 2 * index, uIndex);
	} else {
		update(segment, mid + 1, end, 2 * index + 1, uIndex);
	}

	segment[index].first = segment[2 * index].first + segment[2 * index + 1].first;
	segment[index].second = min(segment[2 * index].second, segment[2 * index].first + segment[2 * index + 1].second);


}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T = 1;
	while (T <= 10) {
		cout << "Test " << T << ":" << endl;

		int N;
		cin >> N;
		string str;
		cin >> str;
		int M;
		cin >> M;
		pair<int, int> *segment = new pair<int, int>[4 * N + 1];
		build(segment, 0, N - 1, 1, str);
		for (int i = 0; i < M; i++) {
			int x;
			cin >> x;
			if (x == 0) {
				if (segment[1].first == 0 && segment[1].second == 0) {
					cout << "YES" << endl;
				} else {
					cout << "NO" << endl;
				}
			} else {
				update(segment, 0, N - 1, 1, x - 1);
			}
		}
		T++;
	}
	return 0;
}