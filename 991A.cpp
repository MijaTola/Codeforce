#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;

    a -= c;
    b -= c;
    if(a < 0 or b < 0) return cout << "-1\n",0;
    n -= c;
    n -= a;
    n -= b;
    if(n >= 1) cout << n << "\n";
    else cout << "-1\n";
    return 0;
}

