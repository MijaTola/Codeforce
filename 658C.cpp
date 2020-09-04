#include <bits/stdc++.h>

using namespace std;

int n,d,h;

vector<int> G[100010];
bool vis[100010];

bool can(int u, int depth) {
    if(depth > h) return 0;
    int ans = 1;
    for (int v: G[u]) 
        ans &= can(v, depth + 1);
    return ans;
}

int main() {
    cin >> n >> d >> h;
    int last = 1;
    int distance = 0;
    for (int i = 0; i < h; ++i) {
        G[last].push_back(last + 1);
        vis[last] = vis[last + 1] = 1;
        distance++;
        last++;
    }
    int dia = 1;
    last++;
    bool first = 1;
    int depth = 0;
    while(distance < d) {
        if(first) {
            G[1].push_back(last), first = 0;
            vis[last] = 1;
            dia = last;
        }
        else {
            G[last].push_back(last + 1);
            vis[last] = vis[last + 1] = 1;
            dia = last + 1;
            last++;
        }
        distance++;
        depth++;
    }

    if(depth > h) return cout << "-1\n",0;
    for (int i = 1; i <= n; ++i)
        if(!vis[i])  {
            if(h == dia) return cout << "-1\n",0;
            G[h].push_back(i);
        }
    if(!can(1,0)) return cout << "-1\n",0;

    for (int i = 1; i <= n; ++i) 
        for (int x: G[i])
            cout << i << " " << x << "\n";
    
    return 0;
}
