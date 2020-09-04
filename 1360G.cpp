#include <bits/stdc++.h>

using namespace std;

int ans[60][60];

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m,a,b;
        scanf("%d %d %d %d", &n, &m, &a, &b);

        memset(ans, 0, sizeof ans);

        vector<int> dy(m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < a; ++j) {
                int mx = 1e9;
                int id = -1;
                for (int k = 0; k < m; ++k) {
                    if(dy[k] < mx) {
                        mx = dy[k];
                        id = k;
                    }
                }
                dy[id]++;
                ans[i][id] = 1;
            }
        }
        
        bool flag = 1;

        for (int i = 0; i < n; ++i) {
            int cnt = 0;
            for (int j = 0; j < m; ++j)
                cnt += ans[i][j];
            flag &= cnt == a;
        }

        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j)
                cnt += ans[j][i];
            flag &= cnt == b;
        }
        
        if(!flag) {
            puts("NO");
            continue;
        }

        puts("YES");

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                printf("%d", ans[i][j]);
            puts("");
        }
                  
    }
    return 0;
}

