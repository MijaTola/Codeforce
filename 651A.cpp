#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	bool sw = false;
	cin >> n >> m;
	if(n <= 1 and m <= 1) return cout << 0,0;
	if(n > m) sw = true;
	int ans = 0;
	while(n > 2 or m > 2){	
		if(!sw){
			n++; m-=2;
		}else{
			n-=2; m++;
		}
		ans++;
	//	cout << n << " " << m << endl;
		if(n <= 2) sw = false;
		else if(m <= 2) sw = true;
	}
	cout << ans+1;
	return 0;
}