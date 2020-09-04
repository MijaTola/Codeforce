#include <bits/stdc++.h>

using namespace std;

int v[110];
bool vis[110];
int n;

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        vis[i] = v[i];
    }
    
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if(vis[i]) continue;
        if(!v[i - 1] or !v[i + 1]) continue;
        v[i + 1] = 0;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}

