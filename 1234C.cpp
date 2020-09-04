#include <bits/stdc++.h>

using namespace std;

int n;
string v[2];

int dp[200010][2][2];
int f(int x, int y, int last) {
    if(x == n) return y == 1;
    if(y == 2) return 0;
    int &ans = dp[x][y][last];
    if(ans != -1) return ans;
    ans = 0;
    if(last == 0) {
        if(v[y][x] == '1' or v[y][x] == '2') 
            ans |= f(x + 1, y, 0);
        if((v[y][x] - '0') >= 3 and (v[y][x] - '0') <= 6) {
            if(y == 0) ans |= f(x, y + 1, 1);
            if(y == 1) ans |= f(x, y - 1, 1);
        }
    } else {
        if((v[y][x] - '0') >= 3 and (v[y][x] - '0') <= 6) {
            ans |= f(x + 1, y, 0);
        }
    }
    
    return ans;
}
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> v[0] >> v[1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2; ++j) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
        int ans = f(0,0,0);
        puts(ans ? "YES": "NO");
    }
    return 0;
}

