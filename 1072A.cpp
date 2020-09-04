#include <bits/stdc++.h>

using namespace std;

int main() {
    int w,h,k;
    cin >> w >> h >> k;
    
    long long ans = 0;
    for (int i = 0, j = 0; i < w and j < h and k; i += 4, j += 4, k--) {
        int dw = w - i;
        int dh = h - j;
        ans += (dw * 2 + dh * 2) - 4;
    }
    cout << ans << "\n";
    return 0;
}

