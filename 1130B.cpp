#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v[300010];
long long dp[300010][2];

long long f(int pos, bool flag) {
    if(pos == n + 1) return 0;
    long long &ans = dp[pos][flag];
    if(ans != -1) return ans;
    ans = LLONG_MAX;
    if(flag) {
        int disA = abs(v[pos][0] - v[pos - 1][0]);
        int disB = abs(v[pos][1] - v[pos - 1][1]);
        ans = min(ans, f(pos + 1, 1) + (disA + disB));
        disA = abs(v[pos][1] - v[pos - 1][0]);
        disB = abs(v[pos][0] - v[pos - 1][1]);
        ans = min(ans, f(pos + 1, 0) + (disA + disB));
    } else {
        int disA = abs(v[pos][0] - v[pos - 1][1]);
        int disB = abs(v[pos][1] - v[pos - 1][0]);
        ans = min(ans, f(pos + 1, 1) + (disA + disB));
        disA = abs(v[pos][0] - v[pos - 1][1]);
        disB = abs(v[pos][1] - v[pos - 1][0]);
        ans = min(ans, f(pos + 1, 0) + (disA + disB));
    }
    return ans;
}

int main() {

    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    v[0] = {0,0};
    cout << min(f(1,0), f(1,1)) << "\n";
    return 0;
}

