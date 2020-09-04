#include <bits/stdc++.h>

using namespace std;

string s;
int n;
long long sum = 0;
int dp[20][3];
int f(int pos, int flag) {
    if(pos == n) return 0;
    int &ans = dp[pos][flag];
    if(ans != -1) return ans;
    ans = 0;
    int lim = 9;
    if(flag) lim = s[pos] - '0';

    for (int i = lim; i >=0 ; --i) {
        if(i == lim and flag) ans = max(ans, f(pos + 1, 1) + i);
        else ans = max(ans, f(pos + 1, 0) + i);
    }
    return ans;
}

void r(int pos, int flag) {
    if(pos == n) return;
    int ans = 0, id = -1, cf = 0;
    int lim = 9;
    if(flag) lim = s[pos] - '0';

    for (int i = lim; i >= 0; --i) {
        if(i == lim and flag) {
            int a = f(pos + 1, 1) + i;
            if(a > ans) {
                ans = a;
                id = i;
                cf = 1;
            }
        } else {
            int a = f(pos + 1, 0) + i;
            if(a > ans) {
                ans = a;
                id = i;
                cf = 0;
            }
        }
    }
    sum = sum * 10 + id;
    r(pos + 1, cf);
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> s;
    n = s.size();
    sum = 0;
    f(0,1);
    r(0,1);
    cout << sum << "\n";
    return 0;
}

