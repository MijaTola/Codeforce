#include <bits/stdc++.h>
using namespace std;

int main(){

	string x;
	cin >> x;
	int c = 0;
	long long ans = 1;
	for (int i = 1; i <= x.size(); ++i)
	{
		int m = x[i] - '0';
		int n = x[i-1] - '0';
		if(m + n == 9) c++;
		else{
			if(c > 0 and c%2 == 0) ans *= c/2+1;
			c = 0;
		}
	}

	cout << ans;
	return 0;
}