#include <bits/stdc++.h>

using namespace std;

int n,k;
bool dig[10];
const int mod = 998244353; 

int dp[200010][1000];

int f(int pos, int sum) {
    if(pos == n) return sum == 0;
    int &ans = dp[pos][sum];
    if(ans != -1) return ans;
    ans = 0;
    if(pos & 1) {
        for (int i = 1; i < 10; ++i) 
            if(dig[i]) ans = (ans + f(pos + 1, sum + i)) % mod;
    } else {
        for (int i = 1; i < 10; ++i) 
            if(dig[i]) ans = (ans + f(pos + 1, sum - i)) % mod;
    }
    //if(dig[0]) ans = (ans + f(pos + 1, sum)) % mod;
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        dig[x] = 1;
    }

    cout << f(0,0) << "\n";
    return 0;
}

