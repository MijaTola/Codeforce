#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;	

bool compare(ii x,ii y){
	if(x.second == y.second) return x.first > y.first;
	return x.second > y.second;
}
int main(){
	int n, c,a, b;
	vector<ii> v;
	c = 1; 
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		v.push_back(make_pair(a,b));
	}

	sort(v.begin(),v.end(), compare);
	int ans = 0;
	int pos = 0;

	/*for (int i = 0; i < n; ++i)
		cout << v[i].second << " ";
	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << v[i].first << " ";*/
	while(c != 0 and pos < n){
		c--;
		ans += v[pos].first;
		c += v[pos].second;
		pos++;
	}

	cout << ans;

	return 0;
}