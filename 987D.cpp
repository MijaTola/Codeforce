#include <bits/stdc++.h>

using namespace std;

int n,m,s,k;
int dis[100010][110];
vector<int> goods[110];
vector<int> G[100010];

void f(int u) {
    queue<pair<int,int> > q;
    
    for (int i = 0; i < (int)goods[u].size(); ++i) {
        q.push(make_pair(goods[u][i],0));
    }

    while(!q.empty()) {
        int x = q.front().first;
        int c = q.front().second;
        q.pop();
        if(dis[x][u] != -1) continue;
        dis[x][u] = c;
        for (int v: G[x]) {
            q.push(make_pair(v, c + 1));
        }
    }
}
int main(){

    ios::sync_with_stdio(false); cin.tie(0);
    memset(dis, -1,sizeof dis);
    cin >> n >> m >> s >> k;

    for (int i = 0; i < n; ++i)  {
        int x; cin >> x;
        goods[x].push_back(i + 1);
    }
    
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    for (int i = 1; i <= s; ++i)  f(i);
    

    for (int i = 1; i <= n; ++i) {
        sort(dis[i] + 1,dis[i] + s + 1);
        int  s = 0;
        for (int j = 1; j <= k; ++j) {
            s += dis[i][j];
        }
        cout << s << " ";
    }
    cout << "\n";
    return 0;
}

