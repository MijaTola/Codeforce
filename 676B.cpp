#include <bits/stdc++.h>

using namespace std;

int n,t;
vector<int> G[100];
double sz[100];
double tot[100];
bool vis[110];

int main(){
    cin >> n >> t;
    vector<int> v;
    v.push_back(1);
    for (int i = 1, cur = 1; i <= n - 1; cur += i + 1, ++i) {
        set<int> s;
        for (int j = 0, ini = cur + 1, p = 0; p < (int)v.size(); ++j, ini++, p++) {
            G[v[p]].push_back(ini);
            G[v[p]].push_back(ini + 1);
            s.insert(ini);
            s.insert(ini + 1);
        }
        v.clear();
        for (int x: s) v.push_back(x);
    }

    vector<int> b;
    b.push_back(1);
    sz[1] = 1;
    vis[1] = 1;

    for (int i = 1; i <= t; ++i) {
        cout << "time: " << i << "\n";
        vector<pair<int,int> > cur;
        for (int x: b) {
            tot[x] += sz[x];
            cout << x << " " << tot[x] << " " << sz[x] << " carajo\n";
            if(tot[x] >= 1) for (int y: G[x]) cur.push_back({y, x});
            else cur.push_back({x, -1});
        }

        b.clear();
        memset(vis, 0, sizeof vis);
        for (auto p: cur) {
            if(!vis[p.first] or p.second == -1) {
                vis[p.first] = 1;
                b.push_back(p.first);
            }
            if(p.second != -1) sz[p.first] += sz[p.second] / 2;
        }
    }

    int ans = 0;

    for (int i = 1; i <= n * (n + 1) / 2; ++i)
        ans += tot[i] >= 1;
    cout << ans << "\n";
   
    return 0;
}


