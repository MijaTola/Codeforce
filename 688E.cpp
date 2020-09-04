#include <bits/stdc++.h>

using namespace std;

int n,dk;
int dp[2][510][510];
int v[510];

int main() {

    cin >> n >> dk;
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    dp[0][0][0] = 1;
    
    int last = 0;
    for (int i = n - 1; i >= 0; --i) {
        int cur = 1 - last;
        for (int j = 0; j <= dk; ++j) {
            for (int k = 0; k <= dk; ++k) {
                dp[cur][j][k] |= dp[last][j][k];
                if(j - v[i] >= 0) {
                    dp[cur][j][k] |= dp[last][j - v[i]][k];
                    if(k - v[i] >= 0) dp[cur][j][k] |= dp[last][j - v[i]][k - v[i]];
                }
            }
        }
        last = cur;
    }

    vector<int> ans;

    for (int i = 0; i <= dk; ++i)
        if(dp[last][dk][i]) ans.push_back(i);

    cout << ans.size() << "\n";
    for (auto x: ans)
        cout << x << " ";
    cout << "\n";


    return 0;
}

