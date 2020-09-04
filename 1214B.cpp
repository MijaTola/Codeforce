#include <bits/stdc++.h>

using namespace std;

int b,g,n;

int main() {
    cin >> b >> g >> n;
    int ans = 0;

    for (int i = 0; i <= b; ++i)
        for (int j = 0; j <= g; ++j)
            ans += (i + j) == n;
    cout << ans << "\n";
    return 0;
}

