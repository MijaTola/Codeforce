#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = n - i;
        if(x % i == 0 and x / i > 0) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

