#include <bits/stdc++.h>

using namespace std;

int n;
int v[10010];
bool vis[10010];
bool first[10010];
int main() {
    
    cin >> n;
    
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(mx, v[i]);
    }
    
    for (int i = 0; i < n; ++i) {
        if(mx % v[i] == 0 and !vis[v[i]] and !first[i]) {
            vis[v[i]] = first[i] = 1;
        }
    }

    int mx2 = 0;

    for (int i = 0; i < n; ++i)
        if(!first[i]) mx2 = max(v[i],mx2);
    cout << mx << " " << mx2 << "\n";
    return 0;
}

