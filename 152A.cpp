#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	char x;
	cin >> n >> m;
	
	int l[105][105];
	bool v[105];
	memset(v, false, sizeof v);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> x;
			int p = x - 48;
			l[i][j] = p;
		}
	
	
	int ans;
	int a = 0;
	for (int i = 0; i < m; ++i)
	{
		int maxi = -1;
		vector<int> t;
		for (int j = 0; j < n; ++j){
		 	if(maxi < l[j][i]){
		 		t.clear();
		 		t.push_back(j);
		 		maxi = l[j][i];
		 	}else if(maxi == l[j][i]) t.push_back(j);
		}
		for (int j = 0; j < t.size(); ++j)
		{
			if(!v[t[j]]){
				a++;
				v[t[j]] = true;
			}
		}
	}
	cout << a << endl;

	return 0;

}