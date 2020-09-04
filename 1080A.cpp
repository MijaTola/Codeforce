#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    int r = n * 2;
    int g = n * 5;
    int b = n * 8;

    int ans = r / k + g / k + b / k + (r % k != 0) 
        + (g % k != 0) + (b % k != 0);
    cout << ans << "\n";
    return 0;
}

