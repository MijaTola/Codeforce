#include <bits/stdc++.h>

using namespace std;


int main(){
	int n,x;
	cin >> n;
	if(n & 1){cout <<-1;return 0;}
		cout << 2;	
	for (int i = 2; i <= n; ++i)
	{
		if(i & 1) cout <<" "<< i+1;
		else cout <<" "<< i-1;
	}
	return 0;
}