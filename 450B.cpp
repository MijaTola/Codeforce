#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,y,n;
	int m= int(1e9+7);
	cin >> x >> y >> n;

	int v[6] = {x-y,x,y,y-x,-x,-y};

	cout <<(v[n%6]%m+m)%m;
	return 0;
}