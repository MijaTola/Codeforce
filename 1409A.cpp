#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    
    cin >> t;

    while(t--) {
        
        int a,b;
        cin >> a >> b;
        if(a > b)
            swap(a,b);

        int df = b - a;

        int ans = df / 10;
        ans += df % 10 != 0;
        cout << ans << "\n";
    }
    return 0;
}

