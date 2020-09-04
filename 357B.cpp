#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,a,b,c;
	cin >> n >> m;
	int v[100123];
	memset(v,0,sizeof v);
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		if(v[a]!=0){
			v[b] = v[a]%3+1;
			v[c] = v[b]%3+1;
		}else if(v[b]!=0){
			v[c] = v[b]%3+1;
			v[a] = v[c]%3+1;
		}else if(v[c]!=0){
			v[a] = v[c]%3+1;
			v[b] = v[a]%3+1;
		}else{
			v[a] = 1;
			v[b] = 2;
			v[c] = 3;
		}
	}

	for (int i = 1; i <= n; ++i)
		cout << v[i] << " "; 
	return 0;
}