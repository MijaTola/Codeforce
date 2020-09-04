#include <bits/stdc++.h>

using namespace std;

int v[110];
int n;

int main() {
    cin >> n;
    set<int> b;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        b.insert(v[i]);
    }
    if(b.size() == 1) return cout << "0\n",0;
    int ans = 1e9;

    for (int k = 0; k <= 10000; ++k) {
        set<int> s;   
        int x = -1;
        int z = 0;
        for (int i = 0; i < n; ++i) {
            x = abs(v[i] - k);
            if(x != 0) {
                s.insert(x);
                z = x;
            }
        }
        if(s.size() == 1) ans = min(ans, z);
    }
    
    if(ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
    return 0;
}

