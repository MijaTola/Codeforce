#include <bits/stdc++.h>

using namespace std;

vector<int> v[30];
long long dp[210][210];
long long sz[210];
string s;
int n,k;

long long f(int pos, int dk) {
    if(dk == 0) return 1;
    long long &ans = dp[pos][dk];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i < 27; ++i) {
        if(v[i].size() == 0) continue;
        int np = upper_bound(v[i].begin(), v[i].end(), pos) - v[i].begin();
        if(np < n and v[i][np] > pos) ans += f(v[i][np], dk - 1);
    }
    return ans;
}

int main () {
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> s;
    for (int i = 0; i < n; ++i) 
        v[s[i] - 'a'].push_back(i + 1);

    for (int i = 1; i <= n; ++i) 
        sz[i] = f(0, i);


    int total = 0;
    sz[0] = 1;
    for (int i = 0; i <= n; ++i) {
        total += sz[i];
    }

    if(total < k) return cout << "-1\n",0;
    long long ans = 0;
    for (int i = n; i >= 0 and k; i--) {
        while(sz[i]-- and k) {
            ans += (n - i);
            k--;
        }
    }

    cout << ans<< "\n"; 
    return 0;
}
