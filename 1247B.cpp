#include <bits/stdc++.h>

using namespace std;

int v[200010];
int a[1000010];

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n,k,d;
        cin >> n >> k >> d;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            a[v[i]] = 0;
        }
        set<int> s;
        for (int i = 0; i < d; ++i) {
            a[v[i]]++;
            s.insert(v[i]);
        }
        int ans = s.size();
        for (int i = d, p = 0; i < n; ++i, p++) {
            a[v[p]]--;
            a[v[i]]++;
            s.insert(v[i]);
            if(a[v[p]] == 0) s.erase(v[p]);
            ans = min(ans, (int)s.size());
        }
        cout << ans << "\n";
    }
    return 0;
}

