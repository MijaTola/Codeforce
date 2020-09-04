#include <bits/stdc++.h>

using namespace std;

long long m,n;
int main() {

    cin >> n >> m;

    if(n == 1) cout << 1 << "\n";
    else if(m == 1) cout << 2 << "\n";
    else if(m == n) cout << m - 1 << "\n";
    else if(m > 1 and m < n) {
        if(m - 1 >= n - m) return cout << m - 1 << "\n", 0;
        else cout << m + 1 << "\n";
        return 0;
    } else if(m == 1 and m + 1 < n) cout << m + 1 << "\n";
    else if(m == n and m - 1 >= 1) cout << m - 1 << "\n";
    else cout << m << "\n";
    return 0;
}

