#include <bits/stdc++.h>

using namespace std;

int main() {
    string a,b;
    cin >> a >> b;
    
    int c = 0, db = 0;;
    for (auto x: b)
        if(x == '1') db++;

    int ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if(i >= (int)b.size()) 
            c -= (a[i - b.size() - 1] == '1');
        c += a[i] == '1';
        if(__gcd(c,db) % 2 == 0 and i >= (int)b.size()) ans++;
        
    }
    cout << ans << "\n";
    return 0;
}

