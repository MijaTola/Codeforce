#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int a = n * (n + 1) / 2;
    if(a & 1) cout << 1 << "\n";
    else cout << 0 << "\n";
    return 0;
}

