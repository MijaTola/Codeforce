#include <bits/stdc++.h>

using namespace std;

int is[1010];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        memset(is, 0, sizeof is);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            is[x] = 1;
        }

        int id = -1;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            if(is[x]) id= x;
        }

        if(id != -1) {
            cout << "YES\n";
            cout << 1 << " " << id << "\n";
        } else cout << "NO\n";
    }
    return 0;
}

