#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,t;
	char q[50];
	cin >> n >> t;
	
	for (int i = 0; i < n; ++i)
		cin >> q[i];

	while(t--){
		bool ver[50];
		memset(ver,false,sizeof ver);
		for (int i = 1; i < n; ++i)
			if(q[i-1] == 'B' and q[i] == 'G' and !ver[i-1] and !ver[i]){ 
				swap(q[i-1],q[i]);
				ver[i-1] = true;
				ver[i] = true;
			}
	}

	for (int i = 0; i < n; ++i)
		cout << q[i];
	
	

	return 0;
}