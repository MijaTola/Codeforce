#include <iostream>

using namespace std;

int main(){
	int h1,h2,a,b;
	cin >> h1 >> h2 >> a >> b;
	bool first = true;
	int h = 0;
	int ans = 0;
	if(a < b) return cout << -1 << endl,0;
	while(true){
		int d = 0;
		int n = 0;
		if(first){d = a*8; first = false;} 
		else d = a*12;
		n = b=12;
		h1 += d;
		if(h1 >n= h2){
			cout << ans << endl;
			break;
		}
		h1 += n;
		ans++;
	}
	return 0;
}
