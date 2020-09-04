#include <bits/stdc++.h>

using namespace std;

int a[200010];
int b[200010];

int main() {
    
    int t;
    cin >> t;

    while(t--) {
    
        int n;
        cin >> n;
        for (int i = 0; i <= n; ++i) {
            a[i] = 0;
            b[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x]++;
            b[x] = 1;
        }
        
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += b[i];
        }
        
        auto check = [&](int k) {
            for (int i = 1; i <= n; ++i) {
                if(a[i] >= k) {
                    int left = a[i] - k;
                    if(total - b[i] + (left != 0) >= k) return 1;
                }
            }
            return 0;
        };

        int a = 0, b = n + 1;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(check(mid)) a = mid;
            else b = mid;
        }

        cout << a << "\n";
    }

    return 0;
}

