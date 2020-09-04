#include <bits/stdc++.h>

using namespace std;
typedef pair<string,int> si;

bool compare(si x, si y){
	if(x.second == y.second) return true;
	return x.second > y.second;
}

int main(){
	int n;
	cin >> n;
	vector <pair<string,int> > a;
	string s;
	int h;
	int v[3000];
	int c = 100;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> h;
		a.push_back(make_pair(s,h));
		v[i] = c;
		c+=10;
	}

	sort(a.begin(),a.end(),compare);

	for (int i = 0; i < a.size(); ++i)
	{
		if(a[i].second > a.size()-i) return cout << -1, 0;
		for (int j = i+1; j < a[i].second; ++j)
		{
			if(v[j])
		}
	}


	return 0;
}