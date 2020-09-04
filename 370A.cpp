#include <bits/stdc++.h>

using namespace std;

int main(){

	int x,y,a,b;

	cin >> a >> b >> x>> y;

	if(a == x || b == y) cout << 1 << " ";
	else cout << 2 << " ";
	if((a + b) % 2 != (x + y) % 2) cout << 0 << " ";
	else{
		if(a + b == x + y ||  x - y  == a - b) cout << 1 << " ";
		else cout << 2 << " ";
	} 
	cout << max(abs(a - x), abs(b - y));
	return 0;
}