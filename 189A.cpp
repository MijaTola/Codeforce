#include <bits/stdc++.h>

using namespace std;
int n,a,b,c,ans;
int K[10000000];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> a >> b >> c;
	memset(K,-1,sizeof K);
	K[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		if(K[i] >= 0){
		K[i+a] = max(K[i+a],K[i]+1);
		K[i+b] = max(K[i+b],K[i]+1);
		K[i+c] = max(K[i+c],K[i]+1);
		}
	}
	cout << K[n];
	return 0;
}