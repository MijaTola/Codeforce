#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;


int main(){
	int n,m,x;
	cin >> n >> m;
	stack<ii> pos;
	int ans = 4;
	for (int i = 0; i < n; ++i)
	{
		for(int j = 0;j < m; ++j){
			cin >> x;
			if(x==1)
				if(i == 0 || i == n-1 || j == 0 || j == m-1) ans = 2; 
		}
	}

	cout << ans;
	return 0;
}
/*
0000
0001
1010
0000
*/