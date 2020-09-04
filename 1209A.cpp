#include <bits/stdc++.h>

using namespace std;

int v[110];
int vis[110];
int main() {
    int n;
    cin >> n;
    
    set<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        s.insert(v[i]);
    }

    sort(v, v + n);
        
    int ans = 0;
    for (int x: s) {
        int flag = 0;
        for (int i = 0; i < n; ++i) {
            if(v[i] % x == 0 and !vis[i]) {
                flag = 1;
                vis[i] = 1;
            }
        }
        
        if(!flag) continue;
        int cnt = 0;

        for (int i = 0; i < n; ++i)
            cnt += vis[i];
        ans++;
        if(cnt == n) break;
    }
    cout << ans << "\n";
    return 0;
}

