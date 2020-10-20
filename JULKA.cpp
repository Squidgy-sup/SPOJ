#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sum(vector<int> &a, vector <int> &b)
{
	int i, j;
	i = a.size() - 1;
	j = b.size() - 1;
	vector < int> ret;
	int sum = 0;
	int carry = 0;
	while (i >= 0 && j >= 0)
	{
		sum = (a[i] + b[j] + carry) % 10;
		carry = (a[i] + b[j] + carry) / 10;
		ret.push_back(sum);
		i--;
		j--;
	}
	while (i >= 0)
	{
		sum = (a[i] + carry) % 10;
		carry = (a[i] + carry) / 10;
		ret.push_back(sum);
		i--;
	}
	while (j >= 0)
	{
		sum = (b[j] + carry) % 10;
		carry = (b[j] + carry) / 10;
		ret.push_back(sum);
		j--;
	}
	if (carry > 0)
		ret.push_back(carry);
	reverse(ret.begin(), ret.end());
	return ret;
}

vector<int> diff(vector <int>&a, vector<int> &b) // a-b , and a >=b
{
	int i = a.size() - 1, j = b.size() - 1;
	vector <int> ret;
	while (i >= 0 && j >= 0)
	{
		if (a[i] < b[j])
		{
			a[i] += 10;
			a[i - 1]--; // borrow
		}
		ret.push_back(a[i] - b[j]);
		j--;
		i--;
	}
	while (i >= 0) // if a was much bigger
	{
		ret.push_back(a[i]);
		i--;
	}
	i = ret.size() - 1;
	while (i > 0)
	{
		if (ret[i] == 0) // if last digit is 0 , then pop it
			ret.pop_back();
		else
			break;
		i--;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

vector <int> div2(vector <int> &a) // division by 2 , always possible
{
	vector <int> ret;
	int i;
	int d;
	d = a[0];
	if (d / 2 != 0)
		ret.push_back(d / 2);
	d %= 2;
	for (i = 1; i < a.size(); i++)
	{
		if (d == 0)
		{
			d = a[i];
		}
		else
		{
			d = d * 10 + a[i];
		}
		ret.push_back(d / 2);
		d = d % 2;
	}
	return ret;
}
void print(vector<int>&a)
{
	for (int x : a)
		cout << x;
	cout << "\n";
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t = 10;
	while (t--)
	{
		vector <int> a, b;
		string sa, sb;
		cin >> sa >> sb;
		int i;
		for (i = 0; i < sa.size(); i++)
			a.push_back(sa[i] - '0');
		for (i = 0; i < sb.size(); i++)
			b.push_back(sb[i] - '0');
		vector <int>  c = sum(a, b); // a+b
		vector <int> x = div2(c);
		vector <int> y = diff(a, x);
		print(x);
		print(y);
	}
	return 0;
}