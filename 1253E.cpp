#include <bits/stdc++.h>

using namespace std;

int n,m,x,y;
int dp[100010];
vector<pair<int,int> > v;

int main() {
    memset(dp, 30, sizeof dp);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        v.emplace_back(x,y);
    }
    
    sort(v.begin(), v.end());
    
    dp[m + 1] = 0;

    return 0;
}

