#include <bits/stdc++.h>

using namespace std;

vector<int> G[1010];
int ds[1010];
int dt[1010];
set<pair<int,int> > st;
int main(){
    memset(ds,-1,sizeof ds);   
    memset(dt,-1,sizeof dt);   
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        st.insert({min(x,y),max(x,y)});
    }
    
    queue<int> q;
    q.push(s);
    ds[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: G[u]) {
            if(ds[v] == -1) {
                q.push(v);
                ds[v] = ds[u] + 1;
            }
        }
    }

    q.push(t);
    dt[t] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v:G[u]) {
            if(dt[v] == -1) {
                q.push(v);
                dt[v] = dt[u] + 1;
            }
        }
    }
    
    int ans = 0;
    int distance = ds[t];
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if(st.count({i,j})) continue;
            int d1 = ds[i] + dt[j] + 1;
            int d2 = ds[j] + dt[i] + 1;
            int d = min(d1,d2);
            if(d >= distance) ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

