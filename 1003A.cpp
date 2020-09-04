#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x]++;
    }
    
    int ans = 0;
    for (int i = 0; i < 110; ++i) {
        ans = max(ans,v[i]);
    }
    cout << ans << "\n";
    return 0;
}

