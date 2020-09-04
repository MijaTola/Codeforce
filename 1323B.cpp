#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];
    
    vector<int> c;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        if(b[i]) cnt++;
        else {
            c.push_back(cnt);
            cnt = 0;
        }
    }
    c.push_back(cnt);

    long long cur = 0, ans = 0, sum = 0;
    
    for (int i = 0; i < n; ++i) {
        if(a[i] == 0) {
            cur = 0, sum = 0;
            continue;
        }
        else cur++;
        for (int x: c) {
            int dv = k / cur;
            if(k % cur == 0) {
                int df = max(x - dv + 1, 0);
                sum += df;
            }
        }
        ans += sum;
    }
    cout << ans << "\n";
    return 0;
}

