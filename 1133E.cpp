#include <bits/stdc++.h>

using namespace std;

int n;
int v[5010];
int ne[5010];
int dp[5010][5010];
int f(int pos, int k) {
    if(pos == n) return 0;
    int &ans = dp[pos][k];
    if(ans != -1) return ans;
    ans = 0;
    if(ne[pos] != -1 and k) 
        ans = max(ans, f(ne[pos] + 1, k - 1) + (ne[pos] - pos + 1));
    if(ne[pos] == -1 and k) 
        ans = max(ans, f(pos + 1, k - 1) + 1);
    ans = max(ans, f(pos + 1, k));
    return ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    int k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);

    for (int i = 0; i < n; ++i) {
        int p = upper_bound(v, v + n, v[i] + 5) - v;
        p--;
        if(p == i) ne[i] = -1;
        else ne[i] = p;
    }
    cout << f(0, k) << "\n";
    return 0;
}

