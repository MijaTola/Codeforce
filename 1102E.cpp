#include <bits/stdc++.h>

using namespace std;

int n, c = 0;
int v[200010];
int dp[200010];
const int mod = 998244353; 
map<int,int> ini,fin;

int main() {

    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        if(!ini.count(v[i])) ini[v[i]] = i;
        fin[v[i]] = i;
    }
    
    int pos = 0;
    int lim = fin[v[pos]];
    c= 0;
    while(pos < n) {
        while(pos < lim) {
            lim = max(lim, fin[v[pos]]);
            pos++;
        }
        lim = fin[v[++pos]];
        if(lim == 0) break;
        c++;
    }
    int ans = 1;
    
    for (int i = 0; i < c; ++i)
        ans = (ans * 2) % mod;
    printf("%d\n",ans);
    return 0;
}

