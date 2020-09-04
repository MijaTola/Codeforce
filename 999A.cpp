#include <bits/stdc++.h>

using namespace std;

int v[110];
int main(){
    
    int n,k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> v[i];

    int a = 0, b = n - 1;
    
    int ans = 0;
    while((v[a] <= k or v[b] <= k) and a <= b and a < n and b >= 0) {
        if(v[a] <= k) {
            a++;
            ans++;
        }else if (v[b] <= k){
            b--;
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

