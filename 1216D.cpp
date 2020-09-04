#include <bits/stdc++.h>

using namespace std;

int n;
long long v[200010];

int main() {
    
    cin >> n;
    long long g = 0;
    long long mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mx = max(v[i], mx);
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i)  {
        sum += (mx - v[i]);
        g = __gcd(g, mx - v[i]);
    }
    cout << (sum) / g << " " << g << "\n";
    return 0;
}

