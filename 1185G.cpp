#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n,T;
vector<pair<int,int> > v;
int dp[1 << 15][250][4];

int subtask1() {
    
    for (int i = 0; i < (1 << 15); ++i) 
        for (int j = 0; j < 4; ++j)
            dp[i][0][j] = 1;
    
    for (int i = (1 << n) - 2; i >= 0; i--) {
        for (int j = 0; j < 250 ; ++j) {
            for (int k = 0; k < 4; ++k) {
                int &ans = dp[i][j][k];
                for (int l = 0; l < n; ++l) {
                    if(!(i & (1 << l)) and v[l].second != k and j - v[l].first >= 0) {
                        ans += dp[i | (1 << l)][j - v[l].first][v[l].second];
                        ans %= mod;
                    }
                }
            }
        }
    }
    return dp[0][T][3];
}

int main() {

    scanf("%d %d", &n, &T);
    

    for (int i = 0; i < n; ++i) {
        int x,y;
        scanf("%d %d", &x, &y);
        y--;
        v.emplace_back(x,y);
    }


    printf("%d\n", subtask1());
    return 0;
}

