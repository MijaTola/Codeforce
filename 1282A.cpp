#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t; 
    while(t--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a > b) swap(a,b);
        int x = c - d;
        int y = c + d;
        if(x > y) swap(x,y);
        int l = max(a, x);
        int r = min(b, y);
        cout << (b - a) - max(r - l , 0) << "\n";
        
    }
    return 0;
}

