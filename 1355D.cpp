#include <bits/stdc++.h>

using namespace std;

int vis[1000010];

int main() {
    
    int n,s;
    scanf("%d %d", &n, &s);
    
    int dn = s;
    int cnt = 0;
    for (int i = 0; i < n - 1; ++i) {
        cnt++;
        dn--;
    }

    for (int i = 1; i <= cnt; ++i) {
        vis[i] = 1;
    }

    for (int i = dn; i <= n; ++i)
        vis[i] = 1;

    for (int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            puts("YES");
            for (int j = 0; j < n - 1; ++j)
                cout << 1 << " ";
            cout << dn << "\n";
            cout << i << "\n";
            return 0;
        }
    }

    puts("NO");
    return 0;
}

