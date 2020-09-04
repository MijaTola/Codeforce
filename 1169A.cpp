#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,a,x,b,y;
    cin >> n >> a >> x >> b >> y;
    x--,a--,b--,y--;
    for (int i = 0; i < 1000; ++i) {
        if(a == b) return cout << "YES\n",0;
        if(a == x) break;
        if(b == y) break;
        a = (a + 1) % n;
        b = ((b - 1) + n) % n;
    }
    cout << "NO\n";
    return 0;
}

