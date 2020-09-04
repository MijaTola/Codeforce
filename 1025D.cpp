#include <bits/stdc++.h>

using namespace std;

int n;
int v[710];
bool can[710][710];
int dp[710][710][2];
int f(int left, int right,bool root) {
    if(left == right) return 1;
    if(dp[left][right][root] != -1) return dp[left][right][root];
    bool ans = 0;
    int proot = (root ? left - 1: right); 
    for (int i = left; i < right; ++i) 
        if(can[proot][i]) ans |= f(left, i, 0) && f(i + 1, right, 1);
    return dp[left][right][root] = ans;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            can[i][j] = (__gcd(v[i],v[j]) != 1);
    
    for (int i = 0; i < n; ++i) 
        if(f(0,i,0) && f(i + 1, n, 1))  return cout << "Yes\n",0;

    cout << "No\n";
    return 0;
}

