#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[200010];
int ans[200010];
int l[200010];
int r[200010];
bool vis[200010];
int main() {
    cin >> n >> k;
    priority_queue<pair<int,int> > q;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        q.push({v[i], i});
        l[i] = i - 1;
        r[i] = i + 1;
    }
    
    bool flag = 1;
    while(!q.empty()) {
        int u = q.top().first;
        int id = q.top().second;
        q.pop();
        if(vis[id]) continue;
        vis[id] = 1;
        if(flag) ans[id] = 1;
        else ans[id] = 2;
        int pos = r[id];
        int pos2 = l[id];
        for (int i = 0; i < k; ++i) {
            if(pos < n) {
                if(flag) ans[pos] = 1;
                else ans[pos] = 2;
                vis[pos] = 1;
                pos = r[pos];
            }
            if(pos2 >= 0) {
                if(flag) ans[pos2] = 1;
                else ans[pos2] = 2;
                vis[pos2] = 1;
                pos2 = l[pos2];
            }
        }
        l[pos] = pos2;
        r[pos2] = pos;
        flag = !flag;
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i];
    cout << "\n";
    return 0;
}

