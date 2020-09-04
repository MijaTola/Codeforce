#include <bits/stdc++.h>

using namespace std;

int n,x;
vector<int> G[100010];
int s[100010];
map<int,int> h;

int dfs(int u = 1, int p = 1) {
    s[u] = 0;
    bool flag = 1;
    for (int v: G[u]) {
        if(v == p) continue;
        s[u] += dfs(v, u);
        flag = 0;
    }
    s[u] += flag;
    return s[u];
}

int main() {
    
    scanf("%d",&n);

    for (int i = 2; i <= n; ++i) {
        scanf("%d",&x);
        G[i].push_back(x);
        G[x].push_back(i);
    }
    
    dfs();
    
    sort(s + 1, s + n + 1);

    for (int i = 1; i <= n; ++i)
        printf("%d ", s[i]);
    puts("");
   
    return 0;
}

