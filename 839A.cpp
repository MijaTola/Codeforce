#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        ans += x;
        if(k > 0) cur++;
        k -= min(ans,8);
        ans -= min(ans,8);
    }
    if(k > 0) puts("-1");
    else cout << cur << "\n";
    return 0;
}

