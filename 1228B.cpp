#include <bits/stdc++.h>

using namespace std;

int h,w;
int r[1010];
int c[1010];
int m[1010][1010];
const int mod = 1e9+7;
long long dp[1010][1010];
long long f(int x, int y) {
    if(x == h) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    if(y == w) return dp[x][y] = f(x + 1, 0) % mod;
    if(m[x][y] == 0) return dp[x][y] = 2 * f(x, y + 1) % mod;
    return dp[x][y] = f(x, y + 1) % mod;
}

int main() {
    memset(dp, -1,sizeof dp);
    cin >> h >> w;

    for (int i = 0; i < h; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < w; ++i) {
        cin >> c[i];
    }
    
    bool flag = 1;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if(c[j] == i) m[i][j] = 2;
            if(r[i] == j) m[i][j] = 2;

            if(i < c[j] or j < r[i]) {
                if(m[i][j] == 2) 
                    flag = 0;
                m[i][j] = 1;
            }
        }
    }
    if(!flag) return cout << "0\n",0;
    cout << f(0,0) << "\n";
    return 0;
}

