#include <bits/stdc++.h>

using namespace std;

int is[1 << 22];
int v[2000010];

void add(int mask, int k) {
    if(is[mask] >= 2) return;
    is[mask]++;
    for (int i = k; i < 21; ++i) {
        if(mask & (1 << i) ) {
            add(mask ^ (1 << i), i + 1);
        }
    }
}

int f(int mask) {
    if(is[0] <= 1) return 0;
    int cur = 0;

    for (int i = 21; i >= 0; i--) {
        if(!(mask & (1 << i)) and is[cur | (1 << i)] >= 2) {
            cur |= (1 << i);
        }
    }
    
    return mask | cur;
}
int main() {

    int n;
    cin >> n;
    
    int ans = 0;

    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    for (int i = n - 1; i >= 0; i--) {
        ans = max(ans, f(v[i]));
        add(v[i], 0);
    }

    cout << ans << "\n";
    return 0;
}

