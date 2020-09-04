#include <bits/stdc++.h>

using namespace std;

int t,n;
string s;
long long a[30][200010];
long long dp[200010][30];
long long f(int pos, int sz, int cur = 0) {
    if(sz == 1) {
        if(s[pos] != cur + 'a') return 1;
        return 0;
    }
    long long &ans = dp[pos][(int)log2(sz)];
    //if(ans != -1) return ans;
    ans = 1e10;
    long long cnt = 0;

    for (int i = pos; i < pos + sz / 2; ++i) 
        cnt += s[i] == cur + 'a';
    
    long long cost = sz / 2 - cnt;
    ans = min(ans, f(pos + sz / 2, sz / 2, cur + 1) + cost);

    cnt = 0;
    for (int i = pos + sz / 2; i < pos + sz; ++i)
        cnt += s[i] == cur + 'a';
    cost = (sz / 2) - cnt;
    ans = min(ans, f(pos, sz / 2, cur + 1) + cost);
    return ans;
}

int main() {

    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;

    while(t--) {

        cin >> n >> s;

        for (int i = 0; i < 30; ++i) 
            for (int j = 1; j < n; ++j)
                a[i][j] += a[i][j - 1];
        
        
        cout << f(0, n) << "\n";
    }

    return 0;
}
