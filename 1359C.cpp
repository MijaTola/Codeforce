#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int h,c,t;
        cin >> h >> c >> t;
        
        long double media = (h + c) / 2;
            long long l = 0, r = 1e14;
            
            auto get = [&] (double x) -> long double {
                long double dh = 1LL * x * h;
                long double dc = 1LL * (x - 1) * c;
                if(x - 1 <= 0) dc = 0;
                long double media = (dh + dc) / (x + (x - 1));
                return media;
            };
            
            for (int i = 0; i < 100; ++i) {
                long long mid = (l + r) / 2;
                if(get(mid) >= t) l = mid;
                else r = mid;
            }
            
            int id = -1;
            long double ans = LLONG_MAX;

            for (long long i = max(0LL, l - 10); i <= l + 10; ++i) {

                if(abs(t - get(i)) < ans) {
                    ans = abs(t - get(i));
                    id = i;
                }
            }

            if(t - media < ans) cout << "2\n";
            else cout << 2 * id - 1 << "\n";
    }

    return 0;
}


