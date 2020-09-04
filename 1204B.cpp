#include <bits/stdc++.h>

using namespace std;

int n,l,r;
int main() {
    cin >> n >> l >> r;


    long long lim = (1LL << (l - 1));
    int cnt = 0;
    long long ans = 0, ans2 = 0;
    while(lim) {
        ans += lim;
        lim >>= 1LL;
        cnt++;
    }
    for (int i = cnt; i < n; ++i) 
        ans++;

    lim = (1LL << (r - 1));
    cnt = 0;
    while(lim) {
        ans2 += lim;
        lim >>= 1LL;
        cnt++;
    }
    
    for (int i = cnt; i < n; ++i) 
        ans2 += (1LL << (r - 1));
    cout << ans << " " << ans2 << "\n";
    return 0;
}

