#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int m,n;
	int a[200000];
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; ++i){ cin >> a[i];}
	sort(a,a+n);
	bool first = true;1
	for (int i = 0; i < m; ++i){
		cin >> x;
		int c = lower_bound(a,a+n,x+1)-a;
		if(first){ cout << c; first = false;}
		else cout<<" "<< c;
	}

	return 0;
}