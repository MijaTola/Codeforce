#include <bits/stdc++.h>

using namespace std;

int v[110];

long long check(int x, int y, int last) {
    if(x == 1 and y == 2) return 3 - (last == 3);
    if(x == 1 and y == 3) return 4;
    if(x == 2 and y == 1) return 3;
    if(x == 2 and y == 3) return -10000000;
    if(x == 3 and y == 1) return 4;
    if(x == 3 and y == 2) return -10000000;
    return 0;
}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    long long ans = 0;
    int last = -1;
    for (int i = 1; i < n; ++i) {
        long long cur = check(v[i - 1], v[i], last);
        ans += cur;
        last = v[i - 1];
    }
    if(ans < 0) return cout << "Infinite\n", 0;
    cout << "Finite\n";
    cout << ans << "\n";
    return 0;
}

