#include <bits/stdc++.h>

using namespace std;

int v[110];
int b[110];
int p[110];

int main() {
    
    int n;
    cin >> n;
    
    int a = 0, bb = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        a += v[i];
        p[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        bb += b[i];
    }
    
    int ans = -1;
    while(a <= bb) {
        int mn = 1e9, id = -1;
        for (int i = 0; i < n; ++i) {
            if(p[i] < mn and v[i] and !b[i]) {
                mn = p[i];
                id = i;
            }
        }
        if(id == -1) break;
        p[id]++;
        a++;
        ans = max(p[id], ans);
    }
    
    for (int i = 0; i < n; ++i)
        ans = max(ans, p[i]);
    if(a <= bb) ans = -1;
    cout << ans << "\n";
    
    return 0;
}

