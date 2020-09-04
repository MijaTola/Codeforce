#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;

    cin >> n;
    
    if(n == 1) return cout << "1 0\n", 0;
    int ans = 1;
    int mx = 0;
        
    set<int> s;
    for (int i = 2; i <= n; ++i) {
        int cnt = 0;
        
        while(n % i == 0) {
            cnt++;
            n /= i;
        }

        if(cnt) {
            ans *= i;
            s.insert(cnt);
            mx = max(mx, cnt);
        }
    }
    
    int p = 1;
    while(p < mx)
        p <<= 1;
    long long ans2 = log2(p);
    cout << ans << " " << ans2 + (s.size() != 1 or p != mx) << "\n";
    return 0;

}

