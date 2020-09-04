#include <bits/stdc++.h>

using namespace std;

int n,m,z;
int v[10010];
int main() {
    
    cin >> n >> m >> z;

    
    int dn = n, dm = m;

    while(dn <= z) v[dn]++, dn += n;
    while(dm <= z) v[dm]++, dm += m;

    int ans = 0;
    for (int i = 1; i <= z; ++i) 
        ans += v[i] == 2;
    cout << ans << "\n";
    return 0;
}

