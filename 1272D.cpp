#include <bits/stdc++.h>

using namespace std;

int n;
int v[200010];
int mx[200010];
int mx2[200010];
int main() {
    
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d", v + i);

    int ans = 0;
    
    int c = 0;

    for (int i = 1; i <= n; ++i) {
        if(v[i] > v[i - 1]) c++;
        else {
            c = 1;
        }
        mx[i] = c;
        ans = max(ans, c);
    }

    v[n + 1] = 1e9 + 1;

    c = 0;
    for (int i = n; i >= 1; i--) {
        if(v[i] < v[i + 1]) c++;
        else {
            ans = max(ans, c);
            c = 1;
        }
        mx2[i] = c;
        ans = max(ans, c);
    }


    for (int i = 1; i <= n; ++i) {
        if(v[i - 1] < v[i + 1]) {
            ans = max(mx[i - 1] + mx2[i + 1], ans);
        }
    }

    cout << ans << "\n";

    return 0;
}

