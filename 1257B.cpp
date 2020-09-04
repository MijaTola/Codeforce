#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        long long x,y;
        cin >> x >> y;

        if(x >= y) {
            puts("yes");
            continue;
        }
        
        long long last = x;
        
        bool flag = 1;
        while(x < y and flag) {
            flag = 0;
            if(x & 1) x--;
            x = x * 3 / 2;
            if(x > last) flag = 1;
            last = x;
        }

        puts(x >= y ? "yes" : "no");
    }
    return 0;
}

