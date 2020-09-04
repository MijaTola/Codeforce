#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[100];
	int n; cin >> n;
	int mini = 99999;
	cin >> a[0];
	int x, y;
	for (int i = 1; i < n; ++i)
	{
		cin >> a[i];
		if(abs(a[i] - a[i-1]) < mini){
			mini = abs(a[i] - a[i-1]);
			x = i-1; y = i;
		}
	}
	if(abs(a[n-1] - a[0]) < mini){ x = n-1; y = 0;}

	cout << x+1 << " " << y+1;
	return 0;
}