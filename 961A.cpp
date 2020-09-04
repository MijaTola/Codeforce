#include <bits/stdc++.h>

using namespace std;

int v[1010];

int main() {
    
    int n,m;
    cin >> n >> m;
        
    set<int> s;
    int ans = 0;
    for (int i = 0 ; i < m; ++i) {
        int x;
        cin >> x;
        x--;
        v[x]++;
        if(!s.count(x) and v[x]) {
            v[x]--;
            s.insert(x);
        }

        while((int)s.size() == n) {
            ans++;
            s.clear();
            for (int j = 0; j < n; ++j)
                if(v[j]) {
                    s.insert(j);
                    v[j]--;
                }
        }
    }
        
    cout << ans << "\n";

    return 0;
}

