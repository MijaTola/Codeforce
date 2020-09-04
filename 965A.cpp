#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n,s,p;
    cin >> k >> n >> s >> p;
    
    int cur = 0;
    while (s * cur < n) cur++;
    int ans = 0;
    while(ans * p < k * cur) ans++;
    cout << ans << "\n";
    return 0;
}

