#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,x,y;
	cin >> n;
	int sumup = 0;
	int sumlow = 0;
	int total = 0;
	bool sw = false;
	bool ver = false;
	int count = 0;
	for (int i = 0; i < n; ++i){
		cin >> x >> y;
		if(x != y) sw = true;
		else if(x % 2!=0) count++;
		sumup += x;
		sumlow += y;
		total += (x%2==0 != y%2==0);
		cout << (x%2==0 != y%2==0) << endl;
	}	
	cout << total << endl;
	if(sumup%2 == 0 && sumlow%2 == 0) cout << 0;
	else if(total%2 == 0 && total > 0) cout << 1;
	else cout << -1;

	return 0;
}