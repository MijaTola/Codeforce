#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int a,b,r;

	cin >> a >> b >> r;

	if(2*r > a || 2*r > b) cout << "Second";
	else cout << "First";
	return 0;
}