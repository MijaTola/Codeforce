#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[100010];
long long a[100010];
long long c[100010];
priority_queue<pair<int,int> > q;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        a[i] = v[i];
    }


    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        q.push({-c[i], -i});
    }

    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> y >> x;
        long long ans = 0;
        y--;

        int cur = a[y];
        if(a[y] < x) {
            x -= a[y];
            ans += a[y] * c[y];
            a[y] = 0;
        } else {
            ans += x * c[y];
            a[y] -= x;
            x = 0;
        }
        while(x and !q.empty()) {
            long long cc = -q.top().first;
            int p = -q.top().second;
            q.pop();
            if(a[p] <= 0) continue;
            if(a[p] < x) {
                x -= a[p];
                ans += a[p] * cc;
                a[p] = 0;
            } else {
                ans += x * cc;
                a[p] -= x;
                x = 0;
            }
            if(a[p] >= 0) q.push({-cc,-p});
        }
        if(!x) cout << ans << "\n";
        else cout << "0\n";
        
    }
    return 0;
}

