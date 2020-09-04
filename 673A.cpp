#include <iostream>

using namespace std;

int main(){
	int n; cin >> n;
	int last = 0;
	int ans = 0;
	bool sw = false;
	for (int i = 0; i < n; ++i){
		int x; cin >> x;
		if(sw) continue;
		if(x - last > 15){
			ans = last+15;
			sw = true;
		}
		last = x;
	}
	if(sw) cout << ans << "\n";
	else if(90-last>15) cout << last+15<<"\n";
	else cout << 90 << "\n";
	return 0;
}
