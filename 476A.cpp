#include <iostream>

using namespace std;

int main(){

	int n,k;
	cin >> n >> k;
	int p = (n+1)/2;
	int ans = (p+k-1)/k*k;
	if(ans > n) ans = -1;

	cout << ans << endl;
		
 	return 0;
}