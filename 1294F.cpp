#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> G[200010];
    set<int> s;
int dis[200010];
int way[200010];
int ans;
int bfs(int u) {
    for (int i = 0; i < 200010; ++i)
        dis[i]= -1, way[i] = 0;

    dis[u] = 0;
    queue<int> q;
    
    ans = 0;
    q.push(u);
    way[u] = u;
    int mx = -1;
    int id = -1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(dis[x] > mx) {
            mx = dis[x];
            id = x;
        }
        for (int v: G[x]) {
            if(dis[v] == -1) {
                dis[v] = dis[x] + 1;
                way[v] = x;
                q.push(v);
            }
        }
    }
    ans = mx;
    return id;
}

pair<int,int> f(int u) {
    dis[u] = 0;
    queue<int> q;
    
    q.push(u);
    way[u] = u;
    int mx = -1;
    int id = -1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(dis[x] > mx) {
            mx = dis[x];
            id = x;
        }
        for (int v: G[x]) {
            if(dis[v] == -1 and !s.count(v)) {
                dis[v] = dis[x] + 1;
                way[v] = x;
                q.push(v);
            }
        }
    }
    //if(id == u) return {1e9, 1e9};
    return {mx, id};
}

int main() {
    
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    
    int a = bfs(1);
    int b = bfs(a);
    int z = b;
    while(way[z] != z) {
        s.insert(z);
        z = way[z];
    }
    s.insert(a);
    s.insert(b);
    memset(dis, -1, sizeof dis);

    int mx = -1, c = -1;
    for (int x: s) {
        auto p = f(x);
        if(p.first > mx) {
            mx = p.first;
            c = p.second;
        }
    }
    cout << ans + mx << "\n";
    if(s.count(c)) {
        for (int i = 1; i <= n; ++i)
            if(i != b and i != a) {
                c = i;
                mx = 0;
                break;
            }
    }
    cout << a << " " << b << " " << c << "\n";
    return 0;
}

