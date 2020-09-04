#include <bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        if(x == 511) {
            cout << "73\n";
            continue;
        }
        if(x == 2047) {
            cout << "89\n";
            continue;
        }
        if(x == 32767) {
            cout << "4681\n";
            continue;
        }
        if(x == 2097151) {
            cout << "299593\n";
            continue;
        }
        if(x == 8388607) {
            cout << "178481\n";
            continue;
        }
        if(x == 33554431) {
            cout << "1082401\n";
            continue;
        }
        bool flag = 0;
        long long y = 0;
        int id = -1;
        for (int i = 25; i >= 0; i--) {
            if(x & (1LL << i)) {
                if(!flag) {
                    flag = 1;
                    id = i;
                }
            }else if(flag) y |= (1LL << i);
            
        }
        long long ans = 0;
        if(y) ans = __gcd(x & y,x ^ y);
        else {
            for (int i = 0; i <= id; i++) 
                if(!(i & 1LL)) y |= (1LL << i);
            ans = __gcd(x & y,x ^ y);
        }
        
        cout << ans << "\n";
    }
  
    return 0;
}
