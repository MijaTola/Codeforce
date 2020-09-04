#include <bits/stdc++.h>

using namespace std;

int n,m;
long long mpow[1000100];
const long long mod = 998244353;
int main() {
    mpow[0] = 1;
    for (int i = 1; i < 1000010; ++i) {
        mpow[i] = (2 * mpow[i - 1]) % mod;
    }

    cin >> n >> m;   
    cout << mpow[n + m] << "\n";
    return 0;
}

