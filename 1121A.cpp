#include <bits/stdc++.h>

using namespace std;

int p[110];
int v[110];
int b[110];
int id[110];
int main() {
    int n,m,k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) 
        cin >> p[i];
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(p[i] > v[x]) {
            v[x] = p[i];
            id[x] = i;
        }

        b[i] = x;
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        x--;
        if(id[b[x]] != x) ans++;
    }
    cout << ans << "\n";
    return 0;
}

