#include <bits/stdc++.h>

using namespace std;

int d[200010];
int vis[200010];

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> v(n);

        for (int &x: v)
            cin >> x;
        
        for (int i = 0; i < n; ++i) {
            d[i] = -1;
            vis[i] = 0;
        }

        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            int cur = i - 1;
            while(cur >= 0 and v[cur] < v[i]) {
                cur = d[cur];
            }
            d[i] = cur;

            if(cur >= 0 and !vis[cur]) {
                ans += v[cur] - v[i];
                vis[cur] = 1;
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}

