#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[200010];
int b[200010];
bool vis[200010];
const int mod = 998244353;

int main() {
    cin >> n >> k;
    for (int i = 0 ; i < n; ++i) {
        cin >> v[i];
        b[i] = v[i];
    }

    sort(b, b + n);
    reverse(b, b + n);

    long long sum = 0;
    
    for (int i = 0; i < k; ++i) {
        sum += b[i];
        vis[b[i]] = 1;
    }

    long long ans = 1;
    int cnt = 0 ;
    bool first = 1;

    for (int i = 0 ; i < n; ++i) {
        if(vis[v[i]]) {
            if(first) first = 0;
            else {
                ans *= cnt;
                ans %= mod;
            }
            cnt = 1;
        } else cnt++;
    }
    cout << sum << " " << ans << "\n";
    return 0;
}

