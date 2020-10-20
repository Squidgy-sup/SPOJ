#include <bits/stdc++.h>
using namespace std;
string needle, haystack;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	while (scanf("%d\n", &n) != EOF)
	{
		getline(cin, needle);
		getline(cin, haystack);
		int found = -1;
		while (true)
		{
			found = haystack.find(needle, found + 1);
			if (found == string::npos)
			{
				break;
			}
			else
			{
				cout << found << "\n";
			}
		}
		cout << "\n";
	}
	return 0;
}