#include <bits/stdc++.h>

using namespace std;

int main() {
    // (( )()( ))
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    
    if(!a and !c and !d) return cout << "1\n",0;
    if(c) {
        if(a == 0 or d == 0) return cout << "0\n",0;
        c = 0;
        a--,d--;
    }

    if(a == d)  a = 0, d = 0;
    if(!a and !d and !c) cout << "1\n";
    else cout << "0\n";
    return 0;
}

