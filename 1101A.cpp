#include <bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;

    while(q--) {
        long long l,r,d;
        cin >> l >> r >> d; 
        if(l > d) cout << d << "\n";   
        else if(d > r) cout << d << "\n";
        else {
            int c = r / d;
            cout << d * ( c + 1) << "\n";
        }
        
    }
    return 0;
}

