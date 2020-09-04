#include <bits/stdc++.h>

using namespace std;

int v[200];
int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,x;
        cin >> n >> x;
        memset(v, 0, sizeof v);
        for (int i = 0; i < n; ++i) {
            int y;
            cin >> y;
            v[y] = 1;
        }
        
        int p = 1;

        while(x > 0) {
            if(!v[p]) {
                p++;
                x--;
            } else p++;
        }

        while(v[p]) p++;
        cout << p - 1 << "\n";
    }

    return 0;
}

