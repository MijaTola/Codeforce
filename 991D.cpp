#include <bits/stdc++.h>

using namespace std;

int n;
string su,sd; 
int dp[110][2][2];
int f(int pos, bool a, bool b) {
    if(pos == n) return 0;
    
    if(dp[pos][a][b] != -1) return dp[pos][a][b];
    int ans = 0;
    
    if(!a and !b  and su[pos] == '0' and sd[pos] == '0' 
            and su[pos + 1] == '0') 
        ans = max(ans,f(pos + 1, 1, b) + 1);

    if(!a and !b  and su[pos] == '0' and sd[pos] == '0' 
            and sd[pos + 1] == '0') 
        ans = max(ans , f(pos + 1, a, 1) + 1);
    
    if(a and !b and sd[pos] == '0' and su[pos + 1] == '0'
            and sd[pos + 1] == '0')
        ans = max(f(pos + 1, 1, 1) + 1,ans);

    if(!a and b and su[pos] == '0' and su[pos + 1] == '0'
            and sd[pos + 1] == '0')
        ans = max(f(pos + 1, 1, 1) + 1,ans);

    if(!a and !b and sd[pos] == '0' and su[pos + 1] == '0'
            and sd[pos + 1] == '0')
        ans = max(f(pos + 1, 1, 1) + 1,ans);

    if(!a and !b and su[pos] == '0' and su[pos + 1] == '0'
            and sd[pos + 1] == '0')
        ans = max(f(pos + 1, 1, 1) + 1,ans);


    ans = max(ans,f(pos + 1, 0, 0));
    return dp[pos][a][b] = ans;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >>su >> sd;   
    n = su.size();
    cout << f(0,0,0) << "\n";
    return 0;
}

