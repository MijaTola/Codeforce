#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k,x,y,u,v, type2;
    long long w,w2;

    scanf("%d %d %d", &n, &m, &k);

    vector<vector<tuple<int,int,int> > > G(n);
    vector<long long> dis(n, LLONG_MAX);
    vector<int> st(n);
    map<pair<int,int>, pair<int,int> > mp;

    auto get = [] (int a,int b) -> pair<int,int> {
        return {min(a,b), max(a,b)};
    };

    for (int i = 0; i < m; ++i) {
        scanf("%d %d %lld", &x, &y, &w);
        x--,y--;
        if(!mp.count(get(x,y)))
            mp[get(x,y)] = {w,0};
        else mp[get(x,y)] = min({w,0}, mp[get(x,y)]);
    }

    for (int i = 0; i < k; ++i) {
        scanf("%d %d", &x, &y);
        x--;
        if(!mp.count(get(0,x)))
            mp[get(0,x)] = {y,i + 1};
        else mp[get(x,0)] = min(make_pair(y, i + 1), mp[get(x,0)]);
    }
    
    for (auto p: mp) {
        int x = p.first.first;
        int y = p.first.second;
        int w = p.second.first;
        int id = p.second.second;
        G[x].push_back({y,w,id});
        G[y].push_back({x,w,id});
    }

    priority_queue<pair<long long, int> > q;
    q.push({0,0});
    dis[0] = 0;
    st[0] = 0;
    while(!q.empty()) {
        w = -q.top().first;
        u = q.top().second;
        q.pop();
        if(dis[u] != -w) continue;
        for (auto p: G[u]) {
            tie(v, w2, type2) = p;
            if(dis[u] + w2 < dis[v]) {
                dis[v] = dis[u] + w2;
                st[v] = max(st[u], type2);
                q.push({-dis[v], v});
            } else if(dis[u] + w2 == dis[v] and max(type2, st[u]) == 0) {
                st[v] = max(type2, st[u]);
                q.push({-dis[v], v});
            }
        }
    }

    set<int> s;
    for (int i = 0; i < n; ++i)  {
        if(st[i]) s.insert(st[i]);
    }
    cout << k - s.size() << "\n";


    return 0;
}

