#include <bits/stdc++.h>

using namespace std;

long long x;
int main() {

    cin >> x;

    set<pair<long long, long long> > ans;
    for (long long n = 1; n <= 2100010; ++n) {
        long long num = 6 * x + n * n * n - n;
        long long den = 3 * n * n + 3 * n;
        if(den and num % den == 0) {
            if(n > num / den) break;
            ans.insert({n, num / den});
            ans.insert({num / den, n});
        }
    }

    cout << ans.size() << "\n";
    
    for (auto p: ans) 
        cout << p.first << " " << p.second << "\n";
    
    return 0;
}

