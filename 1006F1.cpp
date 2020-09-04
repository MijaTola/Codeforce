#include <bits/stdc++.h>

using namespace std;

long long v[25][25];
int n,m;
long long k;
unordered_map<long long, long long> dp[25][25];

long long f(int x,int y, long long cur) {
    if(x == n - 1 and y == m - 1)  return (cur ^ v[x][y]) == k;
    if(x == n or y == m) return 0;
    if(dp[x][y].count(cur)) return dp[x][y][cur];
    long long ans = 0;
    ans += f(x + 1, y, cur ^ v[x][y]);
    ans += f(x, y + 1, cur ^ v[x][y]);
    return dp[x][y][cur] = ans;
}

int main(){
    scanf("%d  %d %lld", &n, &m, &k);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            scanf("%lld", &v[i][j]);
    printf("%lld\n", f(0,0,0));
    return 0;
}

