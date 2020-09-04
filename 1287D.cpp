#include <bits/stdc++.h>


using namespace std;

int n;
int c[2010];
int ans[2010];
vector<int> G[2010];

vector<int> dfs(int u, int p) {
 
    vector<int> current;
    for (int v: G[u]) {
        if(v == p) continue;
        auto b = dfs(v, u);
        for (int x: b)
            current.push_back(x);
    }   
    if((int)current.size() < c[u]) {
        cout << "NO\n";
        exit(0);
    }
    current.insert(current.begin() + c[u], u);
    return current;
}

int main() {

    cin >> n;
        
    int id = -1;
    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p >> c[i];
        if(p) G[p].push_back(i), G[i].push_back(p);
        else id = i;
    }
    auto b = dfs(id, id);
    
    for (int i = 0; i < (int)b.size(); ++i) 
        ans[b[i]] = i + 1;
    
    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

