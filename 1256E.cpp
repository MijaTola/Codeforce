#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int rans[200010];
vector<pair<int,int> > vv;
int dp[200010];

int main() {

    for (int i = 0; i < 200010; ++i)
        dp[i] = 1e9;

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        vv.emplace_back(v[i], i);
    }

    sort(v, v + n);
    sort(vv.begin(), vv.end());

    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--) 
        for (int j = min(i + 2, n); j <= min(i + 50, n - 1); ++j) 
            dp[i] = min(dp[i], dp[j + 1] + v[j] - v[i]);

    int i = 0;
    int cur = 1;
    while(i < n) {
        int ans = 1e9;
        int id = -1;
        for (int j = min(i + 2, n); j <= min(i + 50, n - 1); ++j) 
            if(dp[j + 1] + v[j] - v[i] < ans) {
                ans = dp[j + 1] + v[j] - v[i];
                id = j;
            }

        for (int a = i; a <= id; ++a) 
            rans[vv[a].second] = cur;
        i = id + 1;
        cur++;
    }
    
    cout << dp[0] << " " << cur - 1 << "\n";
    for (int i = 0; i < n; ++i)
        cout << rans[i] << " ";
    cout << "\n";
    return 0;
}

