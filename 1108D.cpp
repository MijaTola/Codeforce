#include <bits/stdc++.h>

using namespace std;

int n;
string s;

char v[] = {'R', 'B', 'G'};
int dp[200010][4];
int f(int pos, int cur) {
    if(pos == n) return 0;

    int &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 1e9;
    for (int i = 0; i < 3; ++i) {
        if(i == cur) continue;
        ans = min(ans, f(pos + 1, i) + (s[pos] != v[i]));
    }
    return ans;
}

void r(int pos, int cur) {
    if(pos == n) return;
    
    int ans = 1e9;
    int id = -1;
    for (int i = 0; i < 3; ++i) {
        if(i == cur) continue;
        if(f(pos + 1, i) + (s[pos] != v[i]) < ans) {
            ans = f(pos + 1, i) + (s[pos] != v[i]);
            id = i;
        }
    }

    cout << v[id];
    r(pos + 1, id);
}
int main() {
    memset(dp, -1, sizeof dp);
    cin >> n >> s;
    cout << f(0,3) << "\n";
    r(0,3);
    cout << "\n";
    return 0;
}

