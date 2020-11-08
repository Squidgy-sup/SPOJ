#include<bits/stdc++.h>
using namespace std;

struct trie {
	trie *child[10];
	bool eow;
};
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		string *arr = new string[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		bool flag = false;
		trie *root = new trie;
		root->eow = false;
		for (int i = 0; i < 10; i++) {
			root->child[i] = NULL;
		}
		for (int i = 0; i < N; i++) {
			string temp = arr[i];
			trie *tempTrie = root;
			for (int j = 0; j < temp.size(); j++) {
				int index = temp[j] - '0';
				if (tempTrie->child[index] == NULL) {
					tempTrie->child[index] = new trie;
					for (int k = 0; k < 10; k++) {
						tempTrie->child[index]->child[k] = NULL;
					}
					tempTrie->child[index]->eow = false;
				}
				tempTrie = tempTrie->child[index];
				if (tempTrie->eow == true) {
					flag = true;
					break;
				}
			}
			if (flag) {
				break;
			}
			tempTrie->eow = true;
		}
		if (flag) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}

	}
	return 0;
}