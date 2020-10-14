#include <bits/stdc++.h>

using namespace std;

int n,a,b,da,db;
vector<int> G[100010];
int dis[100010];

int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> a >> b >> da >> db;
        
        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        auto bfs = [&] (int x) -> pair<int,int> {
            for (int i = 0; i < n + 4; ++i)
                dis[i] = -1;
            queue<pair<int,int> > q;
            q.push({x,0});
            dis[x] = 0;

            int mx = -1, id = -1;

            while(!q.empty()) {
                x = q.front().first;
                int c = q.front().second;
                q.pop();
                if(c > mx) {
                    mx = c, id = x;
                }

                for (int v: G[x]) {
                    if(dis[v] == -1) {
                        dis[v] = c + 1;
                        q.push({v, c + 1});
                    }
                }
            }

            return {id, mx};
        };

        auto p = bfs(a);
        
        if(dis[b] <= da or db < da)  {
            cout << "Alice\n";
            continue;
        }
        int diameter = bfs(p.first).second;
        
        if(2 * da <= db and db <= diameter) {
            cout << "Bob\n";
            continue;
        }

        cout << "Alice\n";
    }
    return 0;
}

