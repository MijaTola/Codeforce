#include <iostream>

using namespace std;

int main(){
 	int n; cin >> n;
	bool ans = true;
	for (int i = 0; i < n; ++i){
		int a,b,c;
		int x,y,z;
		char p;
		cin >> a >> p >> b >> p >> c;
		cin >> x >> p >> y >> p >> z;
		if(!ans) continue;
		int mn = a + 3;
		if(x > mn){
			ans = false; continue;
		}else if(x == mn){
			if(y > b){ans = false; continue;}
			if(b == y){
				if(z >= c){
				 ans = false; continue;	
				}
				
			}
		}
	}
	if(ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
