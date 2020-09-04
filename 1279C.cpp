#include <bits/stdc++.h>

using namespace std;

int t,n,m;
int a[200010];
int b[200010];
int pos[200010];

int main() {
    
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; ++i) {
            scanf("%d", a + i);
            pos[a[i]] = i;
        }

        for (int i = 0; i < m; ++i)
            scanf("%d", b + i);

        set<int> s;
        
        long long ans = 0;
        
        int ini = 0;
        int top = 0;
        for (int i = 0; i < m; ++i) {
            if(s.count(b[i])) {
                ans++;
            } else {
                ans += 2ll * abs(top - pos[b[i]]) + 1;
                for (int j = ini; j <= pos[b[i]]; j++)
                    s.insert(a[j]);
                ini = pos[b[i]] + 1;
            }
            top++;
        }
        cout << ans << "\n";
    }

    return 0;
}

