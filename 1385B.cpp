#include <bits/stdc++.h>

using namespace std;

int v[55];
bool vis[55];

int main() {


    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < 2 * n ;++i)
            cin >> v[i];

        for (int i = 0; i < 2 * n; ++i) {
            if(!vis[v[i]]) {
                cout << v[i] << " ";
                vis[v[i]] = 1;
            }
        }
        cout << "\n";
    }
    return 0;
}

