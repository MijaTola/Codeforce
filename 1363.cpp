#include <bits/stdc++.h>

using namespace std;

int t,n,x;
vector<int> G[1010];
int dis[1010];
int in[1010];

void f(int u, int d = 1, int p = -1) {
    dis[u] = d;
    for (int v: G[u]) {
        if(v == p) continue;
        f(v, d + 1, u);
    }
}

int main() {
    
    cin >> t;
    while(t--) {

        cin >> n >> x;
    
        for (int i = 0; i < 1010; ++i) {
            G[i].clear();
            in[i] = 0;
            dis[i] = 0;
        }

        for (int i = 0; i < n - 1; ++i) {
            int x,y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
            in[x]++, in[y]++;
        }
        
        f(x);
        
        int cnt = 0;
        int b = 0;
        for (int i = 1; i <= n; ++i) {
            if(in[i] == 1) {
                if(dis[i] & 1) cnt++;
                else b++;
            }
        }
        
        if((cnt & 1 and b &1) or in[x] <= 1)  cout << "Ayush";
        else cout << "Ashish";
    }
    return 0;
}

