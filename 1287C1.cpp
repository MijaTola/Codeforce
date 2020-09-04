#include <bits/stdc++.h>

using namespace std;

int n,a,b;
int v[110];
int c[110];

int dp[110][110][110][2];

int f(int pos, int da, int db, int last) {
    if(pos == n) return 0;

    int &ans = dp[pos][da][db][last];
    if(ans != -1) return ans;
    ans = 1e9;
    if(!v[pos]) {
        if(!last) {//even
            if(db) ans = min(ans, f(pos + 1, da, db - 1, 0));
            if(da) ans = min(ans, f(pos + 1, da - 1, db, 1) + 1);
        } else {
            if(db) ans = min(ans, f(pos + 1, da, db - 1, 0) + 1);
            if(da) ans = min(ans, f(pos + 1, da - 1, db, 1));
        }
    } else {
        if(last == v[pos] % 2) 
            ans = min(ans, f(pos + 1, da, db, last));
        else ans = min(ans, f(pos + 1, da, db, v[pos] & 1) + 1);
    }
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n;
    
    a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        c[x]++;
        if(!x) continue;
        if(x & 1) {
            v[i] = 1;
        } else {
            v[i] = 2;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if(!c[i]) {
            if(i & 1) a++;
            else b++;
        }
    }

    cout << min(f(0, a, b, 0), f(0, a, b, 1)) << "\n";;
  
    return 0;
}
