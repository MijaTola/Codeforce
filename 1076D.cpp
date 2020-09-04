#include <bits/stdc++.h>

using namespace std;

long long dis[300010];
bool vis[300010];
int way[300010];
vector<pair<int,int> > G[300010];
vector<pair<pair<int,int>, int> > e;
vector<pair<long long, int> > edges;

void build(int u) {
    
    for (int i = 0; i < 300010; ++i)
        dis[i] = 1e15;

    priority_queue<pair<long long,int> > q;

    q.push({0, u});
    dis[u] = 0;
    way[u] = u;
    while(!q.empty()) {
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for (auto p: G[u]) {
            int v = p.first;
            int w = p.second;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
                way[v] = u;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int x,y,w;
        cin >> x >> y >> w;
        G[x].push_back({y,w});
        G[y].push_back({x,w});
        e.push_back({{x,y}, i + 1});
    }

    build(1);
    
    for (auto p: e) {
        int x = p.first.first;
        int y = p.first.second;
        if(way[x] == y) edges.push_back({dis[y], p.second});
        else if(way[y] == x) edges.push_back({dis[x], p.second});
    }
       
    sort(edges.begin(), edges.end());
    
    while((int)edges.size() > k) 
        edges.pop_back();
    

    cout << edges.size() << "\n";
    for (auto p: edges)
        cout << p.second << " ";
    cout << "\n";
    return 0;
}   
