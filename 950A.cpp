#include <bits/stdc++.h>

using namespace std;

int main(){
    int l,r,a;
    cin >> l >> r >> a;
    
    while(l != r and a) {
        if(l > r) r++,a--;
        else if(l < r) l++,a--;
    }

    int ans = min(l,r) * 2;
    if(l == r) ans += (a / 2) * 2;
    cout << ans << "\n";
    return 0;
}

