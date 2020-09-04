#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int b[200010];
int dp[200010][5];
int dp2[200010][5];

int f(int pos, int mv) {
    if(pos == n + 1) return 0;
    int &ans = dp[pos][mv];
    if(ans != -1) return ans;
    ans = 0;
    if(mv == 1) {
        int last = v[pos - 1] - 1;
        int cur = v[pos];
        if(last < cur - 1) 
            ans = max(ans, f(pos + 1, 1) + 1);

        if(last == cur - 1) 
            ans = max(ans, f(pos + 1, 1));

        if(last < cur) 
            ans = max(ans, f(pos + 1, 2) + 1);

        if(last == cur)
            ans = max(ans, f(pos + 1, 2));
        
        if(last < cur + 1)
            ans = max(ans, f(pos + 1, 3) + 1);

        if(last == cur + 1)
            ans = max(ans, f(pos + 1, 3));
    } 
    if(mv == 2) {
        int last = v[pos - 1];
        int cur = v[pos];
        if(last < cur - 1) 
            ans = max(ans, f(pos + 1, 1) + 1);
        if(last == cur - 1)
            ans = max(ans, f(pos + 1, 1));

        if(last < cur)
            ans = max(ans, f(pos + 1, 2) + 1);

        if(last == cur) 
            ans = max(ans, f(pos + 1, 2));

        if(last < cur + 1)
            ans = max(ans, f(pos + 1, 3) + 1);

        if(last == cur + 1)
            ans = max(ans, f(pos + 1, 3));
    }
    if(mv == 3) {
        int last = v[pos - 1] + 1;
        int cur = v[pos];

        if(last < cur - 1)
            ans = max(ans, f(pos + 1, 1) + 1);

        if(last == cur - 1)
            ans = max(ans, f(pos + 1, 1));

        if(last < cur)
            ans = max(ans, f(pos + 1, 2) + 1);

        if(last == cur) 
            ans = max(ans, f(pos + 1, 2));

        if(last < cur + 1)
            ans = max(ans, f(pos + 1, 3) + 1);

        if(last == cur + 1)
            ans = max(ans, f(pos + 1, 3));

    }
    return ans;
}

int r(int pos, int mv) {
    if(pos == n + 1) return 0;
    int &ans = dp2[pos][mv];
    if(ans != -1) return ans;
    ans = 1e9;
    if(mv == 1) {
        int last = v[pos - 1] - 1;
        int cur = v[pos];
        if(last < cur - 1) 
            ans = min(ans, r(pos + 1, 1) + 1);

        if(last == cur - 1) 
            ans = min(ans, r(pos + 1, 1));

        if(last < cur) 
            ans = min(ans, r(pos + 1, 2) + 1);

        if(last == cur)
            ans = min(ans, r(pos + 1, 2));
        
        if(last < cur + 1)
            ans = min(ans, r(pos + 1, 3) + 1);

        if(last == cur + 1)
            ans = min(ans, r(pos + 1, 3));
    } 
    if(mv == 2) {
        int last = v[pos - 1];
        int cur = v[pos];
        if(last < cur - 1) 
            ans = min(ans, r(pos + 1, 1) + 1);
        if(last == cur - 1)
            ans = min(ans, r(pos + 1, 1));

        if(last < cur)
            ans = min(ans, r(pos + 1, 2) + 1);

        if(last == cur) 
            ans = min(ans, r(pos + 1, 2));

        if(last < cur + 1)
            ans = min(ans, r(pos + 1, 3) + 1);

        if(last == cur + 1)
            ans = min(ans, r(pos + 1, 3));
    }
    if(mv == 3) {
        int last = v[pos - 1] + 1;
        int cur = v[pos];

        if(last < cur - 1)
            ans = min(ans, r(pos + 1, 1) + 1);

        if(last == cur - 1)
            ans = min(ans, r(pos + 1, 1));

        if(last < cur)
            ans = min(ans, r(pos + 1, 2) + 1);

        if(last == cur) 
            ans = min(ans, r(pos + 1, 2));

        if(last < cur + 1)
            ans = min(ans, r(pos + 1, 3) + 1);

        if(last == cur + 1)
            ans = min(ans, r(pos + 1, 3));

    }
    return ans;
}
int main() {
    
    memset(dp, -1, sizeof dp);
    memset(dp2, -1, sizeof dp2);
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        b[v[i]]++;
    }
    
    v[0] = 0;
    sort(v, v + n + 1);

    int cnt = 0;
    int mn = 0;
    for (int i = 0; i < 200010; ++i) {
        if(b[i]) cnt++;
        else {
            mn += (cnt / 3) + (cnt % 3 != 0);
            cnt = 0;
        }

    }
    
    cout << r(1,1) << " " << f(1,1)<< "\n";
    return 0;
}

