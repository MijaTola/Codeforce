#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int r,g,b,w;
        cin >> r >> g >> b >> w;

        int mn = min({r,g,b});
        r -= mn;
        g -= mn;
        b -= mn;
     
        vector<int> v = {r,g,b};
        sort(v.rbegin(), v.rend());
        
    }
    return 0;
}

