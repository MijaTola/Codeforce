#include <bits/stdc++.h>

using namespace std;

int n,m;
int c[510][510];
int dp[510][10000];

int f(int pos, int val) {
    if(pos == n) return val != 0;
    int &ans = dp[pos][val];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < m; ++i) {
        ans |= f(pos + 1, val ^ c[pos][i]);
    }
    return ans;
}

void r(int pos, int val) {
    if(pos == n) return;
    for (int i = 0; i < m; ++i) {
        if(f(pos + 1, val ^ c[pos][i])) {
            cout << i + 1 << " ";
            r(pos + 1, val ^ c[pos][i]) ;
            return;
        }
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j)
            cin >> c[i][j];

    if(!f(0,0)) return cout << "NIE\n",0;
    cout << "TAK\n";
    r(0,0);
    cout << "\n";
    return 0;
}

