#include <bits/stdc++.h>

using namespace std;

int v[110];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }

        long long a = -1, b = 1e10;
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(mid * n >= sum) b = mid;
            else a = mid;
        }
        cout << b << "\n";
    }
    return 0;
}

