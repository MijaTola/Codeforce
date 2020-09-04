#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(){
	int n;
	int v[101];
	cin >> n;
	int maxi = 0;
	int mini = n+1;
	v[maxi] = -1;
	v[mini] = 9999; 
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i];
		//if(v[i] >=  v[maxi]) maxi = i;
		if(v[i] <=  v[mini]) mini = i;
	}

	for (int i = n; i >= 1; --i)
		if(v[i] >=  v[maxi]) maxi = i;
	int ans = n-1-mini + maxi;
	if(mini < maxi) ans--;
	if(n == 1) cout << 0 << endl;
	else cout << ans << endl;
	//cout << mini << " " << maxi << endl;
	return 0;
}	