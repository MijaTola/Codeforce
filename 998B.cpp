#include <bits/stdc++.h>

using namespace std;

int n,b;
int v[110];
int x[110];
int y[110];
int dp[110][110];

int f(int pos, int w) {
    if(pos == n) return 0;
    if(dp[pos][w] != -1) return dp[pos][w];
    int ans = -1e9;
    for (int i = pos; i < n; ++i) {
        int cost = abs(v[i] - v[i + 1]);
        int even = x[i];
        int odd = y[i];
        if(pos) {
            even -= x[pos - 1];
            odd -= y[pos - 1];
        }
        if(even == odd) {
            if(i < n - 1 and w >= cost) ans = max(ans,f(i + 1, w - cost) + 1);
            else ans = max(ans,f(i + 1, w));
        }
    }
    return dp[pos][w] = ans;
}

int main(){
    memset(dp, -1,sizeof dp);

    cin >> n >> b;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] & 1) y[i] = 1;
        else x[i] = 1;
    }

    for (int i = 1; i < n; ++i) {
        x[i] += x[i - 1];
        y[i] += y[i - 1];
    }
    
    cout << f(0,b) << "\n";
    return 0;
}
