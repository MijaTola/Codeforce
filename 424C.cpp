#include <bits/stdc++.h>

using namespace std;

int v[1000010];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    v[1] = 1;
    for (int i = 1; i <= 1000000; ++i)
        v[i] = i ^ v[i - 1];
    
    int n;
    cin >> n;

    int ans = 0;

    for (int i = 2; i <= n; ++i) {
        int d = n / i;
        if(d % 2 != 0) 
            ans ^= v[i - 1];
        ans ^= v[n % i];
    }
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ans ^= x;
    }
    
    cout << ans << "\n";
    return 0;
}

