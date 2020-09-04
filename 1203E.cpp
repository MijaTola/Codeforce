#include <bits/stdc++.h>

using namespace std;

int n;
int v[150010];
int vis[150010];
int main() {

    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];

    sort(v, v + n);

    int a = 0, b = n - 1;

    while(a < b) {
        if(v[a] - 1 > 0 and !vis[v[a] - 1]) vis[v[a] - 1] = 1;
        else if (!vis[v[a]]) vis[v[a]] = 1;
        else if(!vis[v[a] + 1]) vis[v[a] + 1] = 1;

        if(!vis[v[b] + 1]) vis[v[b] + 1] = 1;
        else if (!vis[v[b]]) vis[v[b]] = 1;
        else if(!vis[v[b] - 1]) vis[v[b] - 1]= 1;
        a++, b--;

    }

    
    if(a == b) {
        if(v[a] - 1 > 0 and !vis[v[a] - 1]) vis[v[a] - 1] = 1;
        else if (!vis[v[a]]) vis[v[a]] = 1;
        else if(!vis[v[a] + 1]) vis[v[a] + 1] = 1;
    }

    int ans = 0;

    for (int i = 0; i < 150010;++i)
        ans += vis[i];

    cout << ans << "\n";

    return 0;
}

