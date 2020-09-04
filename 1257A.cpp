#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,x,a,b;
        cin >> n >> x >> a >> b;
        
        if(a > b) swap(a,b);
        
        while(x > 0 and a > 1) a--, x--;
        while(x > 0 and b < n) b++, x--;
        cout << abs(a - b) << "\n";
        
    }
    return 0;
}

