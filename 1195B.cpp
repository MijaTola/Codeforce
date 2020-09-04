#include <bits/stdc++.h>

using namespace std;

int n,k;
int main() {
    cin >> n >> k;
    
    long long a = -1, b = n;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        long long total = (mid * (mid + 1)) / 2;
        long long left = n - mid;
        if(total - left >= k) b = mid;
        else a = mid;
    }
    cout << (b * (b + 1)) / 2 - k << "\n";
    return 0;
}

