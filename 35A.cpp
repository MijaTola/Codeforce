#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int suf[4];
	memset(suf,0,sizeof suf);
	int n;
	cin >> n;
	suf[n] = 1;

	int x,y;
	cin >> x >> y; swap(suf[x],suf[y]);
	cin >> x >> y; swap(suf[x],suf[y]);
	cin >> x >> y; swap(suf[x],suf[y]);

	for (int i = 1; i <= 4; ++i)
	{
		if(suf[i] == 1){
			cout << i; return 0;
		}
	}
	return 0;
}