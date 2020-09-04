#include <bits/stdc++.h>

using namespace std;

int n,m;
int main() {
    cin >> n >> m;
    if(m == 0) return cout << 1 << "\n", 0;
    if(m <= n / 2) return cout << m << "\n", 0;
    cout << n - m << "\n";
    return 0;
}


