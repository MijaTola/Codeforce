#include <bits/stdc++.h>

using namespace std;

int a[300010];
vector<int> v[300010];
int ans[300010];
int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        for (int i = 0; i <= n; ++i) {
            a[i] = 1e9;
            ans[i] = 1e9;
            v[i].clear();
        }

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[x].push_back(i);
            a[x]++;
        }

        for (int i = 1; i <= n; ++i) {
            int last = -1;
            int mx = 0;
            v[i].push_back(n);
            for (int x: v[i]) {
                int d = (x - last - 1);
                mx = max(mx, d);
                last = x;
            }
            ans[mx + 1] = min(ans[mx + 1], i);
        }

        int mn = 1e9;
        for (int i = 1; i <= n; ++i) {
            mn = min(mn, ans[i]);
            if(mn == 1e9) cout << "-1 ";
            else cout << mn<< " ";
        }
        cout << "\n";
    }


    return 0;
}

