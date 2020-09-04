#include <bits/stdc++.h>

using namespace std;

vector<long long> a,b;
int main() {
    long long l,r;
    cin >> l >> r;
    cout << "YES\n";
    for (long long i = 0; i <= (r - l)/ 2; ++i)
        cout << i * 2 + l << " " << i * 2 + l + 1 << "\n";
    return 0;
}

