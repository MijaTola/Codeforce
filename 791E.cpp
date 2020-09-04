#include <bits/stdc++.h>

using namespace std;

int dp[76][76][76][2];
vector<int> v[3];
int main() {

    for (int i = 0; i < 76; ++i)
        for (int j = 0; j < 76; ++j)
            for (int k = 0; k < 76; ++k)
                dp[i][j][k][0] = dp[i][j][k][1] = 1e9;
    string s;
    int n;
    cin >> n >> s;
    
    for (int i = 0; i < n; ++i) {
        if(s[i] == 'V') v[0].push_back(i);
        else if(s[i] == 'K') v[1].push_back(i);
        else v[2].push_back(i);
    }


    auto get = [] (int id, int ini, int fin) {
        int cnt = 0;
        for (int i = ini; i < (int)v[id].size() and v[id][i] < fin; ++i)
            cnt++;
        return cnt;
    };

    dp[v[0].size()][v[1].size()][v[2].size()][1] = dp[v[0].size()][v[1].size()][v[2].size()][0] = 0;

    for (int i = v[0].size(); i >= 0; --i) {
        for (int j = v[1].size(); j >= 0; --j) {
            for (int k = v[2].size(); k >= 0; k--) {
                for (int l = 0; l < 2; ++l) {
                        if(i < (int)v[0].size()) 
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i + 1][j][k][1] + get(1, j, v[0][i]) + get(2, k, v[0][i]));
                        if(j < (int)v[1].size() and !l) 
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j + 1][k][0] + get(0, i, v[1][j]) + get(2, k, v[1][j]));
                        if(k < (int)v[2].size()) 
                            dp[i][j][k][l] = min(dp[i][j][k][l], dp[i][j][k + 1][0] + get(0, i, v[2][k]) + get(1, j, v[2][k]));
                }
            }
        }
    }
    cout << min(dp[0][0][0][0], dp[0][0][0][1]) << "\n";
    return 0;
}

