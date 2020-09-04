#include <bits/stdc++.h>

using namespace std;

int n;
int a[200010];
int dp[200010][2];
int way[200010];

vector<int> G[200010];
vector<int> leaf;

void f(int u, int p = 1) {
    way[u] = p;
    for (int v: G[u]) {
        if(v == p) continue;
        f(v,u);
    }
}

int main(){
    
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    f(1);
    
    return 0;
}

