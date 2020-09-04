#include <bits/stdc++.h>

using namespace std;

int t,n;
int v[200010];
int a[200010];

int main() {

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);


        for (int i = 0; i < 2 * n; ++i) {
            scanf("%d", v + i);
            a[i] = 0;
        }

        auto check = [] () {
            map<int, vector<int> > p;
            for (int i = 0; i <= 2 * n; ++i)
                a[i] = 0;

            for (int i = 2 * n - 1; i >= 0; i--) {
                if(v[i] == 2) a[i] = a[i + 1] + 1;
                else a[i] = a[i + 1] - 1;
            }
        

            for (int i = 0; i < 2 * n; ++i) 
                p[a[i]].push_back(i);

            int cur = 0, ans = 1e9;
            for (int i = 0; i < n; ++i) {
                cur += (v[i] == 1 ? 1 : - 1);
                if(cur == 0) ans = min(ans, 2 * n - i - 1);
                vector<int> &b = p[cur];
                int pos = lower_bound(b.begin(), b.end(), n + 1) - b.begin();
                if(pos >= 0 and pos < (int)b.size()) {
                    int r = b[pos];
                    ans = min(ans, r - i - 1 );
                }
            }

            if(a[0] == 0) ans = 0;
            if(ans == 1e9) ans = 2 * n;
            return ans;
        };

        int ans = check();
        reverse(v, v + 2 * n);
        ans = min(ans, check());
        printf("%d\n", ans);
    }
    return 0;
}

