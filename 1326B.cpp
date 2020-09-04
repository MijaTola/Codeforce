#include <bits/stdc++.h>

using namespace std;

int n;
long long b[200010];

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        long long a = b[i] + mx;
        cout << a << " ";
        mx = max(a, mx);
    }
    cout << "\n";
    return 0;
}

