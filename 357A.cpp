#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,x,y;
	cin >> m;
	int v[102];
	v[0] = 0;
	for (int i = 1; i <= m; ++i)
	{
		int r;
		cin >> r;
		v[i] = v[i-1]+r;
	}
	cin >> x >> y;
	for (int i = 1; i <= m; ++i)
		if(v[i] <= y && v[i] >= x && v[m] - v[i] >= x && v[m] - v[i] <= y){
		 	cout << i + 1 <<endl; return 0;}
	
	cout << 0;
	return 0;
}