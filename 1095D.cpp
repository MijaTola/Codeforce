#include <bits/stdc++.h>

using namespace std;

vector<int> G[200010];
bool vis[200010];
int main() {

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x,y;
        cin >> x >> y;
        G[i].push_back(x);
        G[i].push_back(y);
    }
    
    queue<int> ans;

    ans.push(1);
    int last = 1;
    while((int)ans.size() < n) {
        int u = last;
        vis[u] = 1;
        int x = G[u][0];
        int y = G[u][1];
        
        bool flag = 0;
        for (int i = 0; i < (int)G[x].size(); i++) 
            flag |= G[x][i] == y;

        if(flag and !vis[x]) {
            ans.push(x);
            last = x;
        } else {
            ans.push(y);
            last = y;
        }
    }

    while(!ans.empty())  {
        cout << ans.front() << " ";
        ans.pop();
    }
    
    cout << "\n";

    return 0;
}

