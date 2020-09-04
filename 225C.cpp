#include <bits/stdc++.h>

using namespace std;


int n,m,x,y;
int v[1010];
char s[1010];
int dp[1010][1010][2];
int f(int pos, int cur, bool flag){
    if(pos == m){
        if(cur >= x and cur <= y) return 0;
        return 1e9;
    }
    int ans = 1e9;
    if(dp[pos][cur][flag] != -1) return dp[pos][cur][flag];
    if(cur > y) return 1e9;
    if(flag){
        if(cur >= x and cur <= y){
            ans = min(ans,f(pos + 1,cur + 1,flag) + n - v[pos]);
            ans = min(ans,f(pos + 1, 1, !flag) + v[pos]);
        }
        if(cur < x) ans = min(ans,f(pos + 1,cur + 1,flag) + n - v[pos]);
    }else{
        if(cur >= x and cur <= y){
            ans = min(ans,f(pos + 1,cur + 1, flag) + v[pos]);
            ans = min(ans,f(pos + 1, 1, !flag) + n - v[pos]);
        }
        if(cur < x) ans = min(ans,f(pos + 1,cur + 1,flag) + v[pos]);
    }
    return dp[pos][cur][flag] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    scanf("%d %d %d %d",&n,&m,&x,&y);
    for (int i = 0; i < n; ++i){
        scanf("%s",s);
        for (int j = 0; j < m; ++j){
            if(s[j] == '#') v[j]++;
        }
    }
    printf("%d\n",min(f(0,0,0),f(0,0,1)));
    return 0;
}

