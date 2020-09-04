#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long x, long long y, int p) { 
    long long res = 1;
    x = x % p; 
    while (y > 0) { 
        if (y & 1) res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 


int main() {
    
    long long n,m;
    cin >> n >> m;
    cout << power( (power(2, m, mod) - 1 + mod) % mod, n, mod) << "\n";
    
    return 0;
}

