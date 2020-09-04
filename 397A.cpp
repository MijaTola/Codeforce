#include <bits/stdc++.h>

using namespace std;

int main(){

	bool a[100];
	memset(a,false,sizeof a);
	int n,e,b,x,y;
	cin >> n; n--;
	cin >> b >> e;
	while(n--){
		cin >> x >> y;
		for (int i = x; i < y; ++i)
			a[i] = true;
	}
	int c = 0;
	for (int i = b; i < e; ++i)	if(!a[i]) c++;

	cout << c;
	return 0;
}