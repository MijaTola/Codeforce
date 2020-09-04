#include <bits/stdc++.h>

using namespace std;

pair<string,int> v[100010];
vector<pair<int,string> > g[100010];
int bel[100010];
map<string,int> mp;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k,m; cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        cin >> v[i].first;
        mp[v[i].first] = i;
    }

    for (int i = 1; i <= n; i++) 
        cin >> v[i].second;

    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        while(x--) {
            int y; cin >> y;
            g[i].push_back({v[y].second,v[y].first});
            bel[y] = i;
        }
        sort(g[i].begin(),g[i].end());
    }
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        int pos = mp[s];
        int group = bel[pos];
        ans += g[group][0].first;
        //cout << g[group][0].second << " ";
    }
    cout << ans << "\n";
    return 0;
}

