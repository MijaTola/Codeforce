#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int r,b,k;
        cin >> r >> b >> k;
        if(r > b) swap(r,b);
        int dv = b / r;
        if(b % r == 0 and b != r) dv--;
        cout << dv << "\n";
        puts(dv >= k ? "REBEL" : "OBEY");
    }
    return 0;
}

