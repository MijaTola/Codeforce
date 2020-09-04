#include <bits/stdc++.h>
 
using namespace std;
 
int n;
int a[200010];
int dp[200010][6];
 
int main() {
    
    scanf("%d", &n);
 
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    
    memset(dp, 0, sizeof dp);
 
    for (int i = 0; i < 6; ++i)
        dp[n + 1][i] = 1;
 
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < 5; ++j) {
            for (int k = 0; k < 5; ++k) {
                if(i == 1) {
                    dp[i][j] |= dp[i + 1][k];
                    continue;
                }
 
                if(a[i - 1] < a[i] and j < k) 
                    dp[i][j] |= dp[i + 1][k];
 
                if(a[i - 1] > a[i] and j > k)
                    dp[i][j] |= dp[i + 1][k];
 
                if(a[i - 1] == a[i] and j != k)
                    dp[i][j] |= dp[i + 1][k];
            }
        }
    }
    
    int id = -1;
    for (int i = 0; i < 6; ++i) {
        if(dp[2][i]) {
            id = i;
            break;
        }
    }
 
    if(id == -1) return puts("-1"),0;
 
    vector<int> ans;
    ans.push_back(id + 1);
 
    for (int i = 2; i <= n; ++i) {
        for (int k = 0; k < 5; ++k) {
            if(a[i - 1] < a[i] and id < k and dp[i + 1][k]) {
                ans.push_back(k + 1);
                id = k;
                break;
            }
 
            if(a[i - 1] > a[i] and id > k and dp[i + 1][k]) {
                ans.push_back(k + 1);
                id = k;
                break;
            }
 
            if(a[i - 1] == a[i] and id != k and dp[i + 1][k]) {
                ans.push_back(k + 1);
                id = k;
                break;
            }
        }
    }
 
    for (int x: ans)
        printf("%d ", x);
    puts("");
    return 0;
}
