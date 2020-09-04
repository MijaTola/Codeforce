#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//ios::sync_with_stdio(false); cin.tie(0);
	
	int n,k,x;
	vector<pair<int,int> > a;
	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> x;
		a.push_back(make_pair(x,i));
	}
	sort(a.begin(),a.end());
	set <int> ans;
	int pos = a.size() - k;
	cout << a[pos].first << endl; 
	for (int i = pos; i < a.size(); ++i)
		ans.insert(a[i].second);
	for (std::set<int>::iterator i = ans.begin(); i != ans.end(); ++i)
		cout << *i << " ";
	return 0;
}