#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a,b,c,x,y,z;
        cin >> a >> b >> c >> x >> y >> z;

        long long ans = 0;

        //2 1
        long long mn = min(c, y) ;
        ans += 2 * mn;

        c -= mn;
        y -= mn;
        
        //2 2
        mn = min(c, z);
        c -= mn;
        z -= mn;

        //0 2;

        mn = min(z, a);
        z -= mn;
        a -= mn;

        //1 2
                   
        mn = min(b, z);
        ans -= 2 * mn;

        b -= mn;
        z -= mn;

        
        cout << ans << "\n";

    }
    return 0;
}
