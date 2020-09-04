#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int x,y;
	int h[2550];
	int v[2550];
	cin >> n;
	int t = n*n;
	for (int i = 0; i < t; ++i){
		cin >> x >> y;
		if(h[x] == 0 && v[y] == 0){
			cout << i+1;
			h[x] = 1;v[y]= 1;
				if(t) cout <<" ";
		}
	}
	return 0;
}
