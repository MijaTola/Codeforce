#include <bits/stdc++.h>

using namespace std;

int n;
char s[100010];
char ans[100010];
int dp[100010][2];

int main() {
    
    for (int i = 0; i < 100010; ++i)
        for (int j = 0; j < 2; ++j) 
            dp[i][j] = -1e9;

    scanf("%s", s);
    n = strlen(s);

    dp[0][0] = dp[0][1] = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 2; ++j) {
            int c = s[i - 1] - '0';
            if(c <= j) 
                dp[i][j] = max(dp[i][j], dp[i - 1][c] + 1);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }   

    int cur = 0;
    priority_queue<int> q;

    for (int i = 1; i <= n; ++i) {
        int mx = max(dp[i][0], dp[i][1]);
        if(cur + 1 == mx) {
            ans[i] = '0';
            q.push(i);
            cur++;
        } else {
            ans[i] = '0';
            ans[q.top()] = '1';
            q.pop();
        }
    }
    
    for (int i = 1; i <= n; ++i)
        printf("%c", ans[i]);
    puts("");
    return 0;
}

