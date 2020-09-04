#include <bits/stdc++.h>

using namespace std;

int n;
int a[510];
bool vis[510];
vector<int> v, o, G[510];
vector<pair<int,int> > edges;

pair<int,int> dis(int u) {
    queue<pair<int,int> > q;
    memset(vis, 0, sizeof vis);
    q.push({u,1});
    vis[u] = 1;
    int ans = 0;
    int id = -1;
    while(!q.empty()) {
        int x = q.front().first;
        int c = q.front().second;
        q.pop();
        if(c > ans) {
            ans = c;
            id = x;
        }
        for (int y: G[x]) {
            if(!vis[y]) {
                vis[y] = 1;
                q.push({y, c + 1});
            }
        }
    }
    return {id, ans};
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if(a[i] >= 2) v.push_back(i);
        else {
            o.push_back(i);
            vis[i] = 1;
        }
    }
    
    for (int i = 1; i < (int)v.size() - 1; i++) 
        a[v[i]] -= 2;

    for (int i = 0; i < (int)v.size() - 1; i++) {
        G[v[i]].push_back(v[i + 1]);
        G[v[i + 1]].push_back(v[i]);
        edges.push_back(make_pair(v[i], v[i + 1]));
    }

    if(edges.size()) {
        a[v[0]]--;
        a[v[v.size() - 1]]--;
    }
    
    if(o.size() and v.size()) {
        edges.push_back(make_pair(v[0], o[0]));
        G[v[0]].push_back(o[0]);
        G[o[0]].push_back(v[0]);
        a[v[0]]--;
        a[o[0]]--;
    }
    if(o.size() >= 2 and v.size()) {
        edges.push_back(make_pair(v[v.size() - 1], o[1]));
        G[v[v.size() - 1]].push_back(o[1]);
        G[o[1]].push_back(v[v.size() - 1]);
        a[v[v.size() - 1]]--;
        a[o[1]]--;
    }
    for (int i = 2; i < (int)o.size(); ++i) {
        for (int j = 1; j <= n; ++j) {
            if(j != o[i] and a[j] and a[o[i]] and !vis[j]) {
                a[j]--;
                a[o[i]]--;
                G[o[i]].push_back(j);
                G[j].push_back(o[i]);
                edges.push_back(make_pair(o[i],j));
                break;
            }
        }
    }
  
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < (int)edges.size(); ++i) 
        vis[edges[i].first] = vis[edges[i].second] = 1;

    for (int i = 1; i <= n; ++i) 
        if(!vis[i]) return cout << "NO\n",0;
    pair<int,int > p = dis(1);
    p = dis(p.first);
    cout << "YES " << p.second - 1<< "\n";
    cout << edges.size() << "\n";
    for (int i = 0; i < (int)edges.size(); ++i)
        cout << edges[i].first << " " << edges[i].second << "\n";
    return 0;
}

