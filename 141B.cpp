#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,x,y;

	cin >> a >> x >> y;

	int h = a;
	int pos = 1;
	if(h < y){
		while(h < y){ h = a * pos; pos++;}
		pos--;
	}

	if(h == y or y == 0) return cout << -1, 0;
	if(pos&1 and pos != 1){
		if(x > -a and x != 0 and x < a){
			int t = (pos/2);
			int ans = pos - t;
			ans += t*2;
			if(x < 0) ans--;
			cout << ans;
			return 0;
		}
	}else{
		double mid = (double)a/2;
		double dx = (double)x;
		if(x > -mid and x < mid){
			int t = (pos/2);
			int ans = pos - t;
			ans += t*2;
			if(pos == 1) cout << ans;
			else cout << ans-1;
			return 0;
		}
	}
	cout << -1;

	return 0;
}