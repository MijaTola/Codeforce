#include <bits/stdc++.h>

using namespace std;

int v[200010];
int b[200010];
int c[200010];

int main() {
    
    int n;
    cin >> n;
    int mx = 0;   
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        mx = max(v[i],mx);
    }
        
    v[0] = v[n + 1] = mx;
    for (int i = 1; i <= n + 1; i++) {
        int cur = i - 1;
        while(cur > 0 and v[cur] < v[i]) cur = b[cur];
        b[i] = cur;
    }

    
    for (int i = n; i >= 0; i--) {
        int  cur = i + 1;
        while(cur < n + 1 and v[cur] < v[i]) cur = c[cur]; 
        c[i] = cur;
    }
    bool ans = 1;
    for (int i = 1; i <= n + 1; i++) {
        int x = i;
        int y = b[i];
        int dis = x - y + 1;
        if(dis == 1) continue;
        ans &= !(dis & 1);
    }

    for (int i = n; i >= 0; i--) {
        int x = i;
        int y = c[i];
        int dis = abs(x - y) + 1;
        if(dis == 1) continue;
        ans &= !(dis & 1);
    }
    if(ans)puts("YES");
    else puts("NO");
      
    return 0;
}
