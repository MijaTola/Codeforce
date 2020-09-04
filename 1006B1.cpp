
#include <bits/stdc++.h>

using namespace std;

int v[2010];
int dp[2010][2010];
int n,k; 

int f(int pos, int dk) {
    if(pos == n) {
        if(dk == k) return 0;
        return -1e9;
    }
    if(dp[pos][dk] != -1) return dp[pos][dk];
    if(dk >= k) return -1e9;
    int mx = 0;
    int ans = 0;
    for (int i = pos; i < n; ++i) {
        mx = max(v[i],mx);
        ans = max(ans, f(i + 1, dk + 1) + mx);
    }
    return dp[pos][dk] = ans;
}

void r(int pos, int dk) {
    if(pos == n) return;
    if(dk >= k) return;
    int mx = 0;
    int ans = 0;
    int id = -1;
    for (int i = pos; i < n; ++i) {
        mx = max(v[i], mx);
        if(f(i + 1, dk + 1) + mx > ans) {
            ans = f(i + 1, dk + 1) + mx;
            id = i;
        }
    }
    
    if(id != -1) {
        cout << id - pos + 1 << " ";
        r(id + 1, dk + 1);
    }
}
int main(){
    memset(dp,-1,sizeof dp);

    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
   
    cout << f(0,0) << "\n";
    r(0,0);
    return 0;
}
