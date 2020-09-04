#include <bits/stdc++.h>

using namespace std;

int main() {


    int t;
    cin >> t;

    while(t--) {
        int a,b;
        cin >> a >> b;
        
        if(b > a) swap(a,b);
        
    

        int l = 0, r = b + 1;

        while(r - l > 1) {
            int mid = (r + l) / 2;
            if(a - 2 * mid >= b - mid) l = mid;
            else r = mid;
        }

        int ans = l;
        a -= 2 * ans;
        b -= ans;

        int mn = min(a,b);
        int total = (2 * mn / 3) * 3;

        ans += total / 3;
        cout << ans << "\n";


    }
    return 0;
}



