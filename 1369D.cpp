#include <bits/stdc++.h>

using namespace std;

int c[10000];
vector<int> G[10010];

int f(int u, bool flag) {

    int ans = 0;

    if(!flag and (int)G[u].size() >= 3) {
        int cur = 0;
        for (int v: G[u]) {
            cur += f(v, 1);
        }
        cur++;
        ans = cur;
    }
    int cur = 0;
    for (int  v: G[u]) {
        cur += f(v, 0);
    }
    return max(ans,cur);
}

const int mod = 1e9 + 7;
long long ans[2000010];
int main() {

    int t;
    cin >> t;
    
    ans[10] = 388;

    for (int i = 11; i < 2000010; ++i) {
        ans[i] = (2 * ans[i - 2]) % mod; 
        if(i % 3 == 0) ans[i] = (ans[i] + 4) % mod;
    }
    while(t--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
    return 0;
}

