#include <bits/stdc++.h>

using namespace std;

int n,v;
int dp[110][110];

int f(int pos, int cap) {
    if(pos == n) return 0;
    int &ans = dp[pos][cap];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = 0; cap + i <= v; ++i) {
        int nc = cap + i; 
        if(nc > 0) 
            ans = min(ans, f(pos + 1, nc - 1) + (i * pos));
    }
    return ans;
}

int main() {
    memset(dp, -1,sizeof dp);
    cin >> n >> v;   
    cout << f(1,0) << "\n";
    return 0;
}

