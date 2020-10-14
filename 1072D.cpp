#include <bits/stdc++.h>
 
using namespace std;
 
int n,k;
vector<string> v,c;
int cap[2010][2010];
int dis[2010][2010];
 
int dx[] = {1,0};
int dy[] = {0,1};
 
int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
 
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        v.push_back(x);
        c.push_back(x);
    }
 
    memset(cap, -1, sizeof cap);
    memset(dis, -1, sizeof dis);
    priority_queue<tuple<int,int,int> > q;
    cap[0][0] = k;
    dis[0][0] = 0;
 
    q.push({k,0,0});
    int mx = 0;
    while(!q.empty()) {
        auto [w, x, y] = q.top();
        q.pop();
        if(cap[x][y] <= 0) continue;
        mx = max(mx, dis[x][y]);
        int tot = v[x][y] != 'a';
        c[x][y] = 'a';
        for (int i = 0; i < 2; ++i) {
            int u = x + dx[i];
            int vv = y + dy[i];
            if(u >= 0 and u < n and vv >= 0 and vv < n) {
                if(cap[x][y] - tot > cap[u][vv]) {
                    cap[u][vv] = cap[x][y] - tot;
                    dis[u][vv] = dis[x][y] + 1;
                    q.push({cap[u][vv], u, vv});
                }
            }
        }
    }

 
    pair<int,int> p;
 
    queue<pair<int,int> > qq;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(dis[i][j] == mx and c[i][j] == 'a') {
                qq.push({i,j});
            }
        }
    }
 
    if(qq.empty()) qq.push({0,0});
    for (int i = 0; i < mx; ++i)
        cout << 'a';
 
    while(!qq.empty()) {
        int sz = qq.size();
        char mn = 'z';
        auto l = qq.front();
        cout << c[l.first][l.second];
        for (int i = 0; i < sz; ++i) {
            auto [x,y] = qq.front();
            qq.pop();
            for (int j = 0; j < 2; ++j) {
                int u = x + dx[j];
                int vv = y + dy[j];
                if(u >= 0 and u < n and vv >= 0 and vv < n) {
                    mn = min(mn, c[u][vv]);
                }
            }
            qq.push({x,y});
        }
        
 
        queue<pair<int,int> > q2;
 
        while(!qq.empty()) {
            auto [x,y] = qq.front();
            qq.pop();
            for (int j = 0; j < 2; ++j) {
                int u = x + dx[j];
                int vv = y + dy[j];
                if(u >= 0 and u < n and vv >= 0 and vv < n) {
                    if(mn == c[u][vv]) {
                        q2.push({u,vv});   
                    }
                }
            }
 
        }
 
        qq = q2;
    }
 
    cout << "\n";
 
 
 
    return 0;
}
