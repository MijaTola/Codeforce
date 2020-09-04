#include <bits/stdc++.h>

using namespace std;

int n,m;
long long c[110][110];
long long dp[110][110][3][3];

long long f(int x, int y, int f1, int f2) {
    if(x == n - 1 and y == m - 1) return 0;
    long long ans = 1e18 + 100;
    long long current = c[x][y];

    if(f1 == 0 and f2) {
        long long df = abs(current - c[x][y - 1]) - 1;
        current -= df;
    } 

    if(f1 == 1 and f2) {
        long long df = abs(current - c[x - 1][y]) - 1;
        current -= df;
    }

    if(y + 1 < m) {
        long long cost = abs(current - c[x][y + 1]);
        if(current > c[x][y + 1]) {
            if(!f2) ans = min(ans, f(x, y + 1, 0, 0) + cost + 2);
        } else ans = min(ans, f(x, y + 1, 0, 1) + cost - 1);
    }
    
    if(x + 1 < n) {
        long long cost = abs(current - c[x + 1][y]);
        if(current > c[x + 1][y]) {
            if(!f2) ans = min(ans, f(x + 1, y, 1, 0) + cost + 2);
        } else ans = min(ans, f(x + 1, y, 1, 1) + cost - 1);
    }

    return ans;

}

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                scanf("%lld", &c[i][j]);
    
        printf("%lld\n", f(0,0,2,0));
    }
    return 0;
}

