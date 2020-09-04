#include <bits/stdc++.h>

using namespace std;

int ans[5010];
bool vis[5010][5010];
vector<int> v[5010];
priority_queue<pair<int,int> > q;

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[x].push_back(i);
    }
    
    for (int i = 1; i <= k; ++i) 
        q.push({0,i});

    for (int i = 0; i < 5010; ++i) {
        
        for (int j = 0; j < (int)v[i].size(); ++j) {
            int c = -q.top().first;
            int color = q.top().second;
            q.pop();
            if(vis[color][i]) return cout << "NO\n",0;
            vis[color][i] = 1;
            ans[v[i][j]] = color;
            q.push({-(c + 1), color});
        }
    }

    for (int i = 0; i < n; ++i)
        if(!ans[i]) return cout << "NO\n",0;
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

