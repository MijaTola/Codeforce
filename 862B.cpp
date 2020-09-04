#include <bits/stdc++.h>

using namespace std;

vector<int> G[100010];
int w,b;
int dfs(int u,int p, int h){
    if(h % 2 == 0) w++;
    else b++;
    for (int v: G[u]){
        if(v == p) continue;
        dfs(v,u,h + 1);
    }
}
int main(){
    
    int n;
    scanf("%d", &n);
    w = b = 0;
    for (int i = 0; i < n - 1; ++i){
        int x,y;
        scanf("%d %d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    dfs(1,1,0);
    cout << w << " " << b << "\n";
    long long total = w * b;
    long long ans = total - (n - 1);
    printf("%lld\n",ans);
    return 0;
}

