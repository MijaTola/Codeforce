#include <bits/stdc++.h>

using namespace std;

int const mod = 1e9 + 9;

long long modpow(int x, int y) {
    if(!y) return 1;
    if(y & 1) return modpow(x, y - 1) * x % mod; 
    long long ans = modpow(x,y >> 1);
    return (ans * ans) % mod;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
	int a = n / k;
    int b = n - m;
    int s;
	if(b >= a){
		s=m;
	}else{
	    long long r = modpow(2,a-b+1)-2;while(r<0) r+=mod;
		s = k*r%mod;
		s = (s+(m-(a-b)*k)%mod)%mod;
	}
	cout << s << "\n";
    return 0;
}

