#include <bits/stdc++.h>

using namespace std;

string s;
int sz,k;

int dp[210][210];
char a[210];
int f(int pos, int cur) {
    if(pos == sz) return cur == k;
    if(cur >= 210) return 0;
    int &ans = dp[pos][cur];
    if(ans != -1) return ans;

    ans = 0;
    if(s[pos] == '?') {
        ans |= f(pos + 1, cur);
        ans |= f(pos + 1, cur - 1);
    } else if(s[pos] == '*') {
        ans |= f(pos + 1, cur);
        ans |= f(pos + 1, cur - 1);
        ans |= f(pos, cur + 1);
    } else  ans |= f(pos + 1, cur + 1);
    
    return ans;
}

void r(int pos, int cur) {
    if(pos == sz) return;
    if(cur > k or cur < 0) return;

    if(s[pos] == '?') {
        if(f(pos + 1, cur)) {
            r(pos + 1, cur);
            return;
        }
        if(f(pos + 1, cur - 1)) {
            r(pos + 1, cur - 1);
        }
    }
    else if(s[pos] == '*') {
        if(f(pos + 1, cur)) {
            r(pos + 1, cur);
            return;
        }
        if(f(pos + 1, cur - 1)) {
            r(pos + 1, cur - 1);
            return;
        }
        if(f(pos, cur + 1)) {
            a[cur] = s[pos - 1];
            r(pos, cur + 1);
        }
    } else {
        a[cur] = s[pos];
        r(pos + 1, cur + 1);
        return;
    }
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> s >> k;
    sz = s.size();
    bool ans = f(0,0);
    if(!ans) return cout << "Impossible\n",0;
    r(0,0);
    for (int i = 0; i < k; ++i)
        cout << a[i];
    cout << "\n";
    return 0;
}

