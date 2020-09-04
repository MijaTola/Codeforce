#include <bits/stdc++.h>

using namespace std;

int dp[110][110][110];
int f(int a, int b, int c) {
    int &ans = dp[a][b][c];
    if(ans != -1) return ans;
    ans = 0;
    if(a and b >= 2) 
        ans = max(ans, f(a - 1, b - 2, c) + 3);
    if(b and c >= 2)
        ans = max(ans, f(a, b - 1, c - 2) + 3);
    return ans;
}
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        memset(dp, -1, sizeof dp);
        int a,b,c;
        cin >> a >> b >> c;
        
        cout << f(a,b,c) << "\n";
    }
    return 0;
}

