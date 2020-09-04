#include <bits/stdc++.h>

using namespace std;

int m[55][55];
int a[55];
int ans[55];
bool vis[55];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> m[i][j];
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 0; i < n; ++i) {
            bool flag = 1;
            for (int j = 0; j < n; ++j) 
                if(m[i][j] > k) flag = 0;
            if(flag and !vis[i]) {
                ans[i] = k;
                vis[i] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

