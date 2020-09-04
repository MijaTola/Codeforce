#include <bits/stdc++.h>

using namespace std;

int dx[500010];
int dy[500010];
int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;

    while(q--) {
        int n,m;
        cin >> n >> m;

        char c[n][m];
        for (int i = 0; i < n; ++i) 
            dx[i] = 0;

        for (int i = 0; i < m; ++i) 
            dy[i] = 0;

        
        for (int i  = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char x;
                cin >> x;
                c[i][j] = x;
                if(x == '*') dx[i]++, dy[j]++;
            }
        }
        
        int ans = 1e9;
        int total = n + m - 1;
        for (int i = 0; i < n; ++i) 
            for (int j = 0; j < m; ++j) {
                int cur = dx[i] + dy[j] - (c[i][j] == '*'); 
                ans = min(ans, total - cur);

            }
        cout << ans << "\n";
    }
    return 0;
}

