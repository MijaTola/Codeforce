#include <bits/stdc++.h>

using namespace std;

int v[100010];
int n;
long long p,q,r;
long long dp[100010][3];
long long f(int pos, int cur){
    if(cur == 3) return 0;
    if(dp[pos][cur] != -1) return dp[pos][cur];
    int t = 0;
    if(cur == 0) t = p;
    if(cur == 1) t = q;
    if(cur == 2) t = r;
    long long ans = LLONG_MIN;
    for (int i = pos; i < n; ++i)
        ans = max(ans, f(i,cur + 1) + (long long)v[pos] * t);
    return dp[pos][cur] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d %lld %lld %lld", &n, &p, &q, &r);
    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);
    
    long long ans = LLONG_MIN;
    for (int i = 0; i < n; ++i)
        ans = max(ans,f(i,0));
    printf("%lld\n", ans);
    return 0;
}

