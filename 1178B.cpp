#include <bits/stdc++.h>

using namespace std;

string s;
int sz;

long long dp[1000010][5];
long long f(int pos, int cur) {
    if(cur == 3) return 1;
    if(pos == (int)s.size()) return cur == 3;
    if(pos > (int)s.size()) return 0;
    long long &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 0;
    if(cur == 0 or cur == 2) {
        if(pos + 1 < sz and s[pos] == 'v' and s[pos + 1] == 'v') 
            ans += f(pos + 2, cur + 1);
        ans += f(pos + 1, cur);
    } else {
        if(s[pos] == 'o')ans += f(pos + 1, cur + 1);
        ans += f(pos + 1, cur);
    }
    
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    sz = s.size();
    cout << f(0,0) << "\n";
    return 0;
}

