#include <bits/stdc++.h>

using namespace std;

int v[200010];
int t[200010];
int last[200010];
int vis[200010];

int main() {
    
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
     for (int i = 1; i <= m; ++i)
        cin >> t[i];
    
    
    auto ver = [&](int k) {
        memset(last, -1, sizeof last);
        memset(vis, 0, sizeof vis);

        for (int i = 0; i < k; ++i) 
            if(v[i]) last[v[i]] = i;

        for (int i = 1; i <= m; ++i) {
            if(last[i] != -1) vis[last[i]] = 1;
        }
        int notused = 0;
        int cnt = 0;
        for (int i = 0; i < k; ++i) {
            if(vis[i]) {
                cnt++;
                int needed = t[v[i]];
                if(notused >= needed) {
                    notused -= needed;
                } else return 0;
            } else notused++; 
        }
        if(cnt < m) return 0;
        return 1;
    };


    //cout << ver(4) << "\n";
    //exit(0);
    int a = -1, b = n;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    if(ver(b)) cout << b << "\n";
    else cout << "-1\n";

    return 0;
}

