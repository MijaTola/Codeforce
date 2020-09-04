#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin >> n;
    int ans = -1000000000;
    for (int i = 0; i < n; ++i) {
        double x; cin >> x;
        double d = sqrt(x);
        int y = sqrt(x);
        if(x > ans and y != d) ans = x;

    }
    cout << ans << "\n";
    return 0;
}

