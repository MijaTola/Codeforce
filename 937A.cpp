#include <bits/stdc++.h>

using namespace std;

int v[110];
bool vis[610];
int n;
int main(){
    cin >> n;
    memset(vis,false,sizeof vis);
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        vis[v[i]] = 1;
    }
    sort(v,v + n);
    
    int ans = 0;
    for (int i = 1; i <= 600; ++i) {
        if(!vis[i]) continue;
        bool f = 0;
        for (int j = 0; j < n; ++j) {
            f |= v[j] >= i;
        }
        ans += f;
    }
    cout << ans << "\n";
    return 0;
}

