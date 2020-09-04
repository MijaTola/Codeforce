#include <iostream>
#include <algorithm>
using namespace std;

int main(){	
	
	string a,b;
	
	cin >> a >> b;
	long long ans = 0;
	long long p = 1LL;
	for (int i = a.size()-1; i >= 0; i--){
		int x = a[i] - '0';
		int y = b[i] - '0';
		long long z = abs(x-y);
		z*=p;
		ans += z;
		p*=10;
	}
	cout << ans << endl;
	return 0;
}

