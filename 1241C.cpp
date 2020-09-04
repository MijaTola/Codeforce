#include <bits/stdc++.h>

using namespace std;

long long n,x,da,y,db;
long long k;
long long v[200010];
int c[200010];
bool vis[200010];
vector<pair<int,int> > vv;
bool ver(int z) {
    memset(vis, 0, sizeof vis);
    int pos = n - 1;
    long long sum = 0;
    for (int i = 0; i < (int)vv.size() and pos >= 0; ++i) {
        if(vv[i].second > z) continue;
        if(vv[i].first == 2) {
            sum += ((long long)v[pos--] * (x + y)) / 100;
            vis[vv[i].second] = 1;
        } 
    }

    if(x > y) {
        for (int i = 1; i <= z; ++i) {
            if(i % da == 0 and !vis[i]) {
                sum += (v[pos--] * x) / 100;
                vis[i] = 1;
            }
        }

        for (int i = 1; i <= z; ++i) {
            if(i % db == 0 and !vis[i]) {
                sum += (v[pos--] * y) / 100;
                vis[i] = 1;
            }
        }

    } else {
        for (int i = 1; i <= z; ++i) {
            if(i % db == 0 and !vis[i]) {
                sum += (v[pos--] * y) / 100;
                vis[i] = 1;
            }
        }

        for (int i = 1; i <= z; ++i) {
            if(i % da == 0 and !vis[i]) {
                sum += (v[pos--] * x) / 100;
                vis[i] = 1;
            }
        }
    }
    return sum >= k;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        vv.clear();
        memset(c, 0, sizeof c);
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];

        sort(v, v + n);
        cin >> x >> da >> y >> db >> k;
        
        int pos = da;
        while(pos <= n) {
            c[pos]++;
            pos += da;
        }
        
        pos = db;

        while(pos <= n) {
            c[pos]++;
            pos += db;
        }
    
        for (int i = 1; i <= n; ++i) {
            vv.push_back({c[i], i});
        }
        
        sort(vv.rbegin(), vv.rend());
        int a = -1, b = n;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) b = mid;
            else a = mid;
        }
        if(ver(b)) cout << b << "\n";
        else cout << "-1\n";
    }
    return 0;
}

