#include <bits/stdc++.h>

using namespace std;

int main() {

    char mp[4];
    mp[0] = 'A';
    mp[1] = 'C';
    mp[2] = 'G';
    mp[3] = 'T';
    int n,m;
    cin >> n >> m;
    
    int dp[n + 10][1 << 4];
    int dp2[m + 10][1 << 4];

    for (int i = 0; i < n + 10; ++i)
        for (int j = 0; j < (1 << 4); ++j)
            dp[i][j] = 1e9;
    
    for (int i = 0; i < (1 << 4); ++i)
        dp[n][i] = 0;

    for (int i = 0; i < m + 10; ++i)
        for (int j = 0; j < (1 << 4); ++j)
            dp2[i][j] = 1e9;

    for (int i = 0; i < (1 << 4); ++i)
        dp2[m][i] = 0;


    vector<string> v(n + 1);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < (1 << 4); ++j) {
            if(__builtin_popcount(j) % 2 != 0) continue;
            for (int k = 0; k < (1 << 4); ++k) {
                if(__builtin_popcount(j | k) % 2 != 0 or j == k 
                        or __builtin_popcount(k) != 2) continue;

                vector<char> c;
                for (int l = 0; l < 4; ++l) 
                    if(k & (1 << l)) c.push_back(mp[l]);
                
                int cnt = 0;
                int ini = 0;
                for (int l = 0; l < m; ++l, ini = 1 - ini) 
                    cnt += v[i][l] != c[ini];

                int cnt2 = 0;
                ini = 1;
                for (int l = 0; l < m; ++l, ini = 1 - ini)
                    cnt2 += v[i][l] != c[ini];

                dp[i][j] = min(dp[i][j], dp[i + 1][k] + min(cnt, cnt2));

            }
        }
    }
    
    //columns
    
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < (1 << 4); ++j) {
            if(__builtin_popcount(j) % 2 != 0) continue;
            for (int k = 0; k < (1 << 4); ++k) {
                if(__builtin_popcount(j | k) % 2 != 0 or j == k 
                        or __builtin_popcount(k) != 2) continue;
                vector<char> c;
                for (int l = 0; l < 4; ++l) 
                    if(k & (1 << l)) c.push_back(mp[l]);
                
                int cnt = 0;
                int ini = 0;
                for (int l = 0; l < n; ++l, ini = 1 - ini) 
                    cnt += v[l][i] != c[ini];
                
                int cnt2 = 0;
                ini = 1;
                for (int l = 0; l < n; ++l, ini = 1 - ini)
                    cnt2 += v[l][i] != c[ini];
                
                dp2[i][j] = min(dp2[i][j], dp2[i + 1][k] + min(cnt, cnt2));
            }
        }
    }

    if(dp2[0][0] < dp[0][0]) {
        int current = 0;
        for (int i = 0; i < m; ++i) {
            vector<char> ans;
            int rini = -1;
            int a = 1e9;
            int mask = 0;
            for (int k = 0; k < (1 << 4); ++k) {
                if(__builtin_popcount(current | k) % 2 != 0 or current == k 
                        or __builtin_popcount(k) != 2) continue;
                vector<char> c;
                for (int l = 0; l < 4; ++l) 
                    if(k & (1 << l)) c.push_back(mp[l]);

                int cnt = 0;
                int ini = 0;
                for (int l = 0; l < n; ++l, ini = 1 - ini) 
                    cnt += v[l][i] != c[ini];
                
                int cnt2 = 0;
                ini = 1;
                for (int l = 0; l < n; ++l, ini = 1 - ini)
                    cnt2 += v[l][i] != c[ini];

                if(dp2[i + 1][k] + min(cnt, cnt2) < a) {
                    a = dp2[i + 1][k] + min(cnt, cnt2);
                    ans = c;
                    mask = k;
                    if(cnt < cnt2) {
                        rini = 0;
                    } else {
                        rini = 1;
                    }
                }
            }
            current = mask;
            for (int l = 0; l < n; ++l, rini = 1 - rini)
                v[l][i] = ans[rini];
        }
    } else {
        int current = 0;
        for (int i = 0; i < n; ++i) {
            vector<char> ans;
            int rini = -1;
            int a = 1e9;
            int mask = 0;
            for (int k = 0; k < (1 << 4); ++k) {
                if(__builtin_popcount(current | k) % 2 != 0 or current == k 
                        or __builtin_popcount(k) != 2) continue;
                 vector<char> c;
                for (int l = 0; l < 4; ++l) 
                    if(k & (1 << l)) c.push_back(mp[l]);
                
                int cnt = 0;
                int ini = 0;
                for (int l = 0; l < m; ++l, ini = 1 - ini) 
                    cnt += v[i][l] != c[ini];
                
                int cnt2 = 0;
                ini = 1;
                for (int l = 0; l < m; ++l, ini = 1 - ini)
                    cnt2 += v[i][l] != c[ini];
                
                if(dp[i + 1][k] + min(cnt, cnt2) < a) {
                    a = dp[i + 1][k] + min(cnt, cnt2);
                    ans = c;
                    mask = k;
                    if(cnt < cnt2) {
                        rini = 0;
                    } else {
                        rini = 1;
                    }
                }
              
            }

            current = mask;
            for (int l = 0; l < m; ++l, rini = 1 - rini)
                v[i][l] = ans[rini];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << v[i][j];
        cout << "\n";
    }
    return 0;
}

