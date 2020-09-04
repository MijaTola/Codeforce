#include <bits/stdc++.h>

using namespace std;

int v[1010];
int in[1010];
int n,m;
int cost;
vector<pair<int, pair<int,int> > > e;
int main() {
    int t;
    cin >> t;
    while(t--) {
        e.clear();
        scanf("%d %d", &n, &m);

        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", v + i);
            ans += 2 * v[i];
        }

        if(m <= n - 1 or n == 2) {
            puts("-1");
            continue;
        }
    
        cout << ans << "\n";
        
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << " " << (i + 1) % n + 1 << "\n";
        }
        
        
    }
    return 0;
}

