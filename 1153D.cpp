#include <bits/stdc++.h>

using namespace std;

int n;
int in[300010];
int dp[300010];
int kind[300010];
vector<int> G[300010];

void f(int u) {
    if(in[u] == 0) {
        dp[u] = 1;
        return;
    }
    if(kind[u] == 1) dp[u] = 1e9;
    for (int v: G[u]) {
        f(v);
        if(kind[u] == 1) {
            dp[u] = min(dp[u], dp[v]);
        } else {
            dp[u] += dp[v];
        }
    }

}

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", kind + i);

    for (int i = 2; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        in[x]++;
        G[x].push_back(i);
    }


    int leaf = 0;

    for (int i = 1; i <= n ;++i)
        leaf += in[i] == 0;
    
    f(1);

    printf("%d\n", leaf - dp[1] + 1);
    

    return 0;
}

