#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int c[200010];
bool vis[200010];
int main() {

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        c[v[i]]++;
    }

    int id = -1;
    int mx = 0;

    for (int i = 0; i < 200010; ++i) {
        if(c[i] > mx) {
            mx = c[i];
            id = i;
        }
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) 
        if(v[i] == id) {
            vis[i] = 1;
            q.push(i);
        }

    vector<pair<int,pair<int,int> > > ans;
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        if(pos - 1 >= 0 and !vis[pos - 1] and v[pos - 1] != id) {
            vis[pos - 1] = 1;
            if(v[pos] > v[pos - 1]) ans.push_back({1, {pos - 1, pos}});
            else ans.push_back({2, {pos - 1, pos}});
            v[pos - 1] = id;
            q.push(pos - 1);
        }
        if(pos + 1 < n and !vis[pos + 1] and v[pos + 1] != id) {
            vis[pos + 1] = 1;
            if(v[pos] < v[pos + 1]) ans.push_back({2, {pos + 1, pos}});
            else ans.push_back({1, {pos + 1, pos}});
            v[pos + 1] = id;
            q.push(pos + 1);
        }
    }

    cout << ans.size() << "\n";
    for (auto x: ans) 
        cout << x.first << " " << x.second.first + 1 << " " << x.second.second + 1 << "\n";
    return 0;
}

