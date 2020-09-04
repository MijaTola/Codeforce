#include <bits/stdc++.h>

using namespace std;

int v[1000000];
int main(){
	int n,x;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int pos = -1;
	
	for (int i = 0; i < n-1; ++i)
	{
		if(v[i] > v[i+1]){
			pos = i; break;
		}
	}
	if(pos == -1){
		cout << 0; return 0;
	}

	for (int i = pos+1; i < n - 1; ++i)
	{
		if(v[i] > v[i+1]){
			cout << -1;
			return 0;
		}
	}
	if(v[n-1] > v[0]){
			cout << -1;
			return 0;
	}
	cout << n - pos -1;
	return 0;
}
