#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,a,b,c,d;
        cin >> n >> a >> b >> c >> d;
        
        int down = n * (a - b);
        int up = n * (a + b);
        int mv = up - down;
        int left = max(down,c - d);
        int df = left - down;
        
        if(df <= mv and df >= 0 and left <= c + d) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
