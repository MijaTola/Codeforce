#include <bits/stdc++.h>

using namespace std;

int m,n,t,a,b,x;
pair<int,int> p[200010];

int main() {

    scanf("%d", &m);

    while(m--) {
        vector<int> e,h;
        scanf("%d %d %d %d", &n, &t, &a, &b);
        
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            p[i].second = x;
            total += (x ? b : a);
        }

        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            p[i].first = x;
        }

        if(total <= t) {
            printf("%d\n", n);
            continue;
        }
        sort(p, p + n);
        
        for (int i = 0; i < n; ++i) {
            if(p[i].second) h.push_back(p[i].first);
            else e.push_back(p[i].first);
        }
        
        for (int i = 1; i < (int)h.size(); ++i)
            h[i] += h[i - 1];

        for (int i = 1; i < (int)e.size(); ++i)
            e[i] += e[i - 1];

        long long cur = 0;
        int num = 0;
        int ans = 0;
        int de = 0, dh = 0;
        
        auto check = [] (long long time, int ini) {
            int a = -1, b = n - 1;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(p[mid].first <= time) b = mid;
                else a = mid;
            }
            return b == ini;
        };

        for (int i = 0; i < n; ++i) {
            if(p[i].second) {
                dh++;
                cur += b;
            } else {
                de++;
                cur += a;
            }

            cout << p[i].second << ": "<< cur << " " << p[i].first << " test\n";
            if(cur <= p[i].first or check(cur, i)) {
                cout << "in\n";
                long long left = p[i].first - cur;
                de = left / a;
                int z = e.size() - de;
                num = i + 1;
                long long mn = min(de, z);
                num += mn;
                de -= mn;
                left -= de * a;
                dh = left / b;
                mn = min(dh, (int)h.size() - dh);
                num += mn;
                ans = max(ans, num);
            } 
        }

        printf("%d\n", ans);
    }
    return 0;
}

