#include <iostream>

using namespace std;


int main(){
	int n; cin >> n;
	int mn = 1e8;
	int mx = -1;
	int pmx;
	int pmn;
	for (int i = 0; i < n; ++i){
		int x; cin >> x;
		if(x > mx){
			mx = x;
			pmx = i;
		}
		if(x < mn){
			mn = x;
			pmn = i;
		}
	} 
	int ans = -1;
	ans = max(ans,abs(n-1 - pmx));
	ans = max(ans,pmx);
	ans = max(ans,abs(n-1 - pmn));
	ans = max(ans,pmn);
	cout << ans << "\n";
	return 0;
}
