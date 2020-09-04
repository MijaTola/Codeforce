#include <bits/stdc++.h>

using namespace std;

int v[110];

bool vis[110];
int main() {
    int n,k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        memset(vis, 0, sizeof vis);
        for (int j = i; j < n; j += k) 
            vis[j] = 1;

        for (int j = i - k; j >= 0; j -= k)
            vis[j] = 1;
        
        int a = 0;
        int  b = 0;
        for (int i = 0; i < n; ++i) {
            if(!vis[i]) {
                if(v[i] == 1) a++;
                else b++;
            }
        }


        ans = max(ans, abs(b - a));
        
    }
    cout << ans << "\n";
    return 0;
}

