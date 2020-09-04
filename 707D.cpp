#include <bits/stdc++.h>

using namespace std;

int row[100010], col[100010], type[100010];
int ans[100010];
bitset<1010> m[1010], change;
bool done[100010];
vector<int> G[100010];

void dfs(int u, int res) {

    if(type[u] == 1) {
        if(!m[row[u]][col[u]]) {
            m[row[u]][col[u]] = 1;
            done[u] = 1;
            res++;
        }
    }

    if(type[u] == 2) {
        if(m[row[u]][col[u]]) {
            m[row[u]][col[u]] = 0;
            done[u] = 1;
            res--;
        }
    }

    if(type[u] == 3) {
        res -= m[row[u]].count();
        m[row[u]] ^= change;
        res += m[row[u]].count();
        done[u] = 1;
    }

    ans[u] = res;

    for (int v: G[u]) 
        dfs(v, res);
    
    if(type[u] == 1 and done[u]) {
        m[row[u]][col[u]] = 0;
    }

    if(type[u] == 2 and done[u]) {
        m[row[u]][col[u]] = 1;
    }
    if(type[u] == 3 and done[u]) {
        m[row[u]] ^= change;
    }
    
    
}
int main() {

    int n,m,q;
    cin >> n >> m >> q;
    
    for (int i = 0; i < m; ++i)
        change[i] = 1;

    for (int i = 1; i <= q; ++i) {
        cin >> type[i];
        if(type[i] <= 2) {
            cin >> row[i] >> col[i];
            col[i]--;
        } else  cin >> row[i];
        
        if(type[i] == 4) G[row[i]].push_back(i);
        else G[i - 1].push_back(i);
    }
    
    dfs(0, 0);

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
    return 0;
}
