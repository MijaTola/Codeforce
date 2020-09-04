#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,y;

	cin >> x >> y;
	
	long long ans = 0;
	for (int i = 2; i <= x; i += 2)
	{
		for (int j = 2; j <= y; j += 2)
		{
			ans += (x-i+1)*(y-j+1);
		}
	}

	cout << ans;
}