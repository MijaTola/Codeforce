#include <bits/stdc++.h>

using namespace std;

int n,m;
int v[110];
int main() {
    
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int mx = -1;
        int id = -1;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if(x > mx) {
                mx = x;
                id = j;
            }
        }
        v[id]++;
    }
    
    int mx = 0;
    for (int i = 0; i < n; ++i) 
        mx = max(mx, v[i]);

    for (int i = 0; i < n; ++i)
        if(mx == v[i]) return cout << i + 1 << "\n", 0;

    return 0;
}

