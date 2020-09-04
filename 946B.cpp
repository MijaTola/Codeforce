#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long n,m; 
    cin >> n >> m;
    while(n != 0 and m != 0 and (n >= 2 * m or m >= 2 * n)) {
        long long dm = 2 * m;
        long long d = n / dm;
        if(!dm) break;
        if(d) n -= (d * dm);
        if(!n) continue;
        long long dn = 2 * n;
        if(!dn) break;
        long long d2 = m / dn;
        if(d2) m -= (d2 * dn);
    }
    cout << n << " " << m << "\n";
    return 0;
}

