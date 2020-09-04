#include <bits/stdc++.h>

using namespace std;

int n;
char v[5010];
int dp[5010][5010];
const int mod = 1e9 + 7;
int f(int pos, int in) {
    if(pos == n) return 1;
    
    if(dp[pos][in] != -1) return dp[pos][in];
    int ans = 0;

    if(v[pos] == 's') {
        if(pos and v[pos - 1] != 'f' and in)
            ans = (ans + f(pos, in - 1)) % mod;
        ans = (ans + f(pos + 1, in)) % mod;
    }else {
        if(pos and v[pos - 1] != 'f' and in )
            ans = (ans + f(pos, in - 1)) % mod;
        ans = (ans + f(pos + 1, in + 1)) % mod;
    }
    return dp[pos][in] = ans % mod;
}
int main(){
    memset(dp, -1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    cout << f(0,0) << "\n";
    return 0;
}

