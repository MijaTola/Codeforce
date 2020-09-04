#include <bits/stdc++.h>

using namespace std;

int main() {
    int k,r;
    cin >> k >> r;
    int dk = k;
    int ans = 1;
    while(k % 10 != 0 and k % 10 != r) {
        ans++;
        k += dk;
    }
    cout << ans << "\n";
    return 0;
}
