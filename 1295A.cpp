#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string ans = "";
        while(n > 3) {
            ans += "1";
            n -= 2;
        }
        
        if(n == 3) ans = "7" + ans;
        if(n == 2) ans = "1" + ans;
        cout << ans << "\n";
    }
    return 0;
}

