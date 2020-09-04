#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,n;
	int a,b;
	int p1 = -1, p2 = 1000;
	cin >> n >> x;
	bool sw = true;
	for (int i = 0; i < n; ++i)
	{
		cin >> a >> b;
		if(a > b) swap(a,b);
		if(a > p2 or b < p1) sw = false;
		if(a > p1) p1 = a;
		if(b < p2) p2 = b;
	}
	if(!sw) return cout << -1,0;
	if(p1 <= x and x <= p2) cout << 0;
	else if(x < p1) cout << p1 - x;
	else if(x > p2) cout << x - p2; 
	else cout << -1;
	return 0;
}