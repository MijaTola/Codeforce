#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[2500010];
pair<int, pair<int,int> > v[300010];

int bs(int x) {
    int a = -1, b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(v[mid].first >= x) b = mid;
        else a = mid;
    }
    return b;
}

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) 
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;
    
    sort(v, v + n);

    for (int i = 2000010; i >= 0; i--) {
        int pos = bs(i);
        if(pos < n)dp[i] = max(dp[i], dp[v[pos].first + v[pos].second.second] + v[pos].second.first);
        dp[i] = max(dp[i], dp[i + 1]);
    }
  
    cout << dp[0] << "\n";
    return 0;
}

