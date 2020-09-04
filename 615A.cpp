#include <bits/stdc++.h>

using namespace std;
int main(){
	int n,m,x,z;
	//bool v[101];
	cin >> n >> m;
	//memset(v,false,sizeof v);
	/*for (int i = 0; i < n; ++i)
	{
		cin >> x;
		for (int i = 0; i < x; ++i)
		{
			cin >> z;
			v[z] = true;	
		}
	}

	for (int i = 1; i <= m; ++i)
	{
		if(!v[i]){
			cout << "NO";
			return 0;
		}
	}

*/
	set<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		for (int i = 0; i < x; ++i)
		{
			cin >> z;
			v.insert(z);	
		}
	}

	if(v.size() == m) cout << "YES";
	else cout << "NO";
	return 0;
}