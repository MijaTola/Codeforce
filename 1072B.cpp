#include <bits/stdc++.h>

using namespace std;

int n;
int a[100010];
int b[100010];
int dp[100010][4];
int f(int pos, int last) {
    if(pos == n) return 1;
    int &ans = dp[pos][last];
    if(ans != -1) return ans;
    ans = 0;
    for (int i = 0; i <= 3; ++i) {
        int cur = last | i;
        int cur2 = last & i;
        if(cur == a[pos - 1] and cur2 == b[pos - 1]) {
            ans |= f(pos + 1, i);
        }
    }
    return ans;
}

void r(int pos, int last) {
    if(pos == n) return;

    for (int i = 0; i <= 3; ++i) {
        int cur = last | i;
        int cur2 = last & i;
        if(cur == a[pos - 1] and cur2 == b[pos - 1]) {
            if(f(pos + 1, i)) {
                cout << i << " ";
                r(pos + 1, i);
                return;
            }
        }
    }
}

int main() {
    memset(dp, -1, sizeof dp);
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i)
        scanf("%d", a + i);
    for (int i = 0; i < n - 1; ++i)
        scanf("%d", b + i);

    bool ans = 0;
    for (int i = 0; i <= 3; ++i) 
        ans |= f(1, i);

    if(!ans) return puts("NO"),0;
    puts("YES");
    for (int i = 0; i <= 3; ++i) {
        if(f(1,i)) {
            cout << i << " ";
            r(1,i);
            break;
        }
    }
    cout << "\n";
    return 0;
}

