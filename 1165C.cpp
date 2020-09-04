#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int dp[200010][27][3];

int f(int pos, int last, bool flag) {
    if(pos == n) {
        if(!flag) return 0;
        return 1e9;
    }
    int &ans = dp[pos][last][flag];
    if(ans != -1) return ans;
    ans = 1e9;
    if(flag) {
        if(s[pos] == (char)(last + 'a')) ans = min(ans, f(pos + 1, last, 1) + 1);
        else {
            ans = min(ans, f(pos + 1, last, 1) + 1);
            ans = min(ans, f(pos + 1, last, 0));
        }
    } else {
        ans = min(ans, f(pos + 1, last, 0) + 1);
        ans = min(ans, f(pos + 1, s[pos] - 'a', 1));
    }
    return ans;
}

void r(int pos, char last, bool flag) {
    if(pos == n) return;

    if(flag) {
        if(s[pos] == last) r(pos = 1, last, 1);
        else {
            int a1 = f(pos + 1, last, 1) + 1;
            int a2 = f(pos + 1, last, 0);
            if(a2 < a1) {
                cout << s[pos];
                r(pos + 1, last, 0);
            } else r(pos + 1, last, 1);
        }
    } else {
        int a1 = f(pos + 1, last, 0) + 1;
        int a2 = f(pos + 1, s[pos] - 'a', 1);
        if(a2 < a1) {
            cout << s[pos];
            r(pos + 1, s[pos] - 'a', 1);
        } else r(pos + 1, last, 0);
    }
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    cout << f(0, 0, 0) << "\n";
    r(0,0,0);
    cout << "\n";
    return 0;
}

