#include <bits/stdc++.h>

using namespace std;

int n;
int v[5010];
int dp[5010][5010];
vector<int> b;

//5 4 1 4 5 5 1 5

int f(int l, int r, bool flag) {
    if(l > r) return 0;
    int ans = 1e9;
    for (int i = l; i <= r; ++i) {
        if(v[i] == v[l]) {
            
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
      return 0;
}

