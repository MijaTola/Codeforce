#include <bits/stdc++.h>

using namespace std;

int n,p;
const int mod = 1e9 + 7;

int dp[55][2500];

int f(int pos, int sum) {
    if(pos == n) return 1;
    int ans = 0;
    for (int i = 1; i <= p; ++i) {
        if((sum + i) % p == 0) continue;
        ans += f(pos + 1, sum + i);
    }
    return ans;
}
int main() {
    
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &p);
        printf("%d\n", f(0,0));
    }
    return 0;
}

