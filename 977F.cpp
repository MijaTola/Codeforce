#include <bits/stdc++.h>

using namespace std;

int v[200010];

int main() {

    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    map<int,int> dp;
    int ans = 0, id = -1;
    for (int i = n - 1; i >= 0; i--) {
        dp[v[i]] = max(dp[v[i]], dp[v[i] + 1] + 1);
        if(dp[v[i]] > ans) {
            ans = dp[v[i]];
            id = v[i];
        }
    }
    
    cout << ans << "\n";


    for (int i = 0; i < n and ans; ++i) {
        if(v[i] == id) {
            cout << i + 1 << " ";
            id++;
            ans--;
        }
    }
    cout << "\n";
    return 0;
}
