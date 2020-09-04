#include <bits/stdc++.h>

using namespace std;

int v[100010];
int dp[100010];

int main() {
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    vector<int> dv;

    for (int i = 1; i * i < n; ++i)
        if(n % i == 0) {
            dv.push_back(i);
            if(i != n / i and (n / i) < n / 2) 
                dv.push_back(n / i);
        }
    
    for (int x: dv) {
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < x; ++i)
            dp[i] = v[i];
    
        for (int i = 0; i < n; ++i) 
            if(v[(i + x) % n])dp[(i + x) % n] += dp[i];
        
        for (int i = 0; i < n; ++i) 
            if(dp[i] >= 2) return puts("YES"),0;
    }
    puts("NO");
    return 0;
}

