#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int m,n;
	if(a*d == c*b){
		cout << 0 << "/" << 1; return 0;
	}else if(a*d - c*b > 0){
		m = a*d - c*b;
		n = a *d;	
	}else{
		m = c*b - a*d; n =c*b; 
	}
	int t = __gcd(m,n);
	cout << m/t << "/" << n/t;
	return 0;	
}