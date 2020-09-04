#include <bits/stdc++.h>

using namespace std;

int v[1010];
int b[1010];

int main(){
    
    int n,m; cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    int a = 0;
    int c = 0;
    int ans = 0;
    while(a < n and c < m) {
        if(b[c] >= v[a]) {
            ans++;
            c++;
        }
        a++;
    }
    cout << ans << "\n";
    return 0;
}

