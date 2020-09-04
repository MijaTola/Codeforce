#include <bits/stdc++.h>
using namespace std;

int main(){
	int dx[101];
	int dy[101];
	memset(dx,0,sizeof dx);
	memset(dy,0,sizeof dy);
	int n,k;
	cin >> n >> k;
	int column = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(column == j) cout << k << " ";
			else cout << 0 << " ";
		}
		cout << endl;
		column++;
	}
	return 0;
}