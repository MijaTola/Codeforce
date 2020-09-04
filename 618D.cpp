#include <bits/stdc++.h>

using namespace std;

long long n,x,y;
vector<int> G[200010];
long long in[200010];
long long cnt = 0;

int dfs(int u, int p) {
    int can = 2;
    for (int v: G[u]) 
        if(v != p) {
            if(dfs(v, u) and can)
                cnt++, can--;
        }

    return can;
}

int main() {

    cin >> n >> x >> y;


    for (int i = 0; i < n - 1; ++i) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
        in[a]++;
        in[b]++;
    }


    long long ans = 0;
    if(x < y) {
        dfs(1,1);
        ans = cnt * x + y * (n - cnt - 1);
    } else {
        long long mx = 0;
        for (int i = 1; i <= n; ++i) mx = max(in[i],mx);
        ans += (n - 2) * y ;
        if(mx == n - 1) ans += x;
        else ans += y;
    }
    
    
    cout << ans << "\n";
   
    return 0;
}

