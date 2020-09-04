#include <bits/stdc++.h>

using namespace std;

vector<pair<long long, long long> > v[200010];

long long dp[3][12];

int main() {
    
    int n;
    scanf("%d", &n);
        
    for (int i = 0; i < n; ++i) {
        int k;
        scanf("%d", &k);
        priority_queue<int> q[4];
        for (int j = 0; j < k; ++j) {
            int x,y;
            scanf("%d %d", &x, &y);
            q[x].push(y);
        }
        
        for (int l = 1, lim = 3; l <= 3; ++l, lim--) {
            for (int j = 0; j < lim and !q[l].empty(); ++j) {
                v[i].push_back({q[l].top(), l} );
                q[l].pop();
            }
        }

        sort(v[i].begin(), v[i].end());
    }
    
    int last = 0;

    for (int i = n - 1; i >= 0; i--) {
        int cur = 1 - last;
        for (int j = 0; j <= 10; ++j) {
            auto &ans = dp[cur][j] = 0;
            do {
                int lim = 0;
                int p = 0;
                long long sum = 0;
                int cnt = j;
                while(p < (int)v[i].size() and lim + v[i][p].second <= 3) {
                    long long mul = cnt + 1 == 10 ? 2 : 1;
                    lim += v[i][p].second;
                    sum += 1LL * v[i][p].first * mul;
                    p++;
                    cnt = (cnt + 1) % 10; 
                    ans = max(ans, dp[last][cnt] + sum); 
                }
                ans = max(ans, dp[last][j]);
            } while(next_permutation(v[i].begin(), v[i].end()));
        }
        last = cur;
    }

    printf("%lld\n", dp[last][0]);

    return 0;
}
