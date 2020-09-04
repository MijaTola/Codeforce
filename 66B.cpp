#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,x;
	int v[1000];
	cin >> n;
	int ans = 1;
	int p = 0;
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	for (int i = 0; i < n; ++i)
	{
		int posd = i, posi = i;
		int c = 1;
		while(v[posd] >= v[posd+1]){
			if(posd + 1 < n) posd++;
			else break;
			c++;
		}
		while(v[posi] >= v[posi-1] and posi - 1 >= 0){
			if(posi - 1 >= 0) posi--;
			else break;
			c++;
		}
 		ans = max(ans,c);
 	}

	cout << ans;

	return 0;
}