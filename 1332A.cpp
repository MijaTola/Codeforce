#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        long long a,b,c,d,x,y,x1,y1,x2,y2;
        cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
        
        if(a or b) {
            if(x2 == x1) {
                cout << "NO\n";
                continue;
            }
        }

        if(c or d) {
            if(y1 == y2) {
                cout << "NO\n";
                continue;
            }
        }
        x -= a;
        x += b;
        y -= c;
        y += d;

        if(x1 <= x and x <= x2 and y1 <= y and y <= y2)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

