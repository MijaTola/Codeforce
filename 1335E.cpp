#include <bits/stdc++.h>

using namespace std;

vector<int> v[210];
int s[200010][210];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i <= 200; ++i)
            v[i].clear();

        for (int i = 0; i < 201; ++i) {
            for (int j = 0; j <= n; ++j)
                s[i][j] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[x].push_back(i);
            s[x][i] = 1;
        }
        
        for (int i = 1; i <= 200; ++i)
            for (int j = n - 1; j >= 0; j--)
                s[i][j] += s[i][j + 1];

        auto get = [&] (int a, int b) {
            
            int x = 0, y = v[a].size() - 1;
            int mx = 0;

            while(x < y) {
                int vx = v[a][x];
                int vy = v[a][y];
                int val = s[b][vx + 1] - s[b][vy + 1]; 
                mx = max(mx, 2 * (x + 1) + val);
                x++, y--;
            }
            return mx;
        };
        
        int ans = 0;
        for (int i = 1; i <= 200; ++i)
            for (int j = 1; j <= 200; ++j) {
                ans = max(ans, (int)v[i].size());
                if(i == j) continue;
                ans = max(ans, get(i,j));
            }
        
        cout << ans << "\n";
    }
    return 0;
}
 
