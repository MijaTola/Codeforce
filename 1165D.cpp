#include <bits/stdc++.h>

using namespace std;

long long v[310];
bool dv[1000010];

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(dv, 0, sizeof dv);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)  {
            cin >> v[i];
            dv[v[i]] = 1;
        }
        sort(v, v + n);

        long long ans = v[0] * v[n - 1];
        int a = 0, b = n - 1;
        bool flag = 1;
        while(a <= b) {
            if(v[a] * v[b] != ans) flag = 0;
            a++, b--;
        }

        for (long long i = 2; i * i <= ans; ++i) {
            if(ans % i == 0) {
                int l = i;
                int r = ans / i;
                if(!dv[l] or !dv[r]) flag = 0;
            }
        }
        if(flag) cout << ans << "\n";
        else cout << "-1\n";
    }

    return 0;
}
