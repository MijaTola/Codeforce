#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    long long s1 = sqrt(n);

    long long a = -1, b = 1e9;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(mid * s1 >= n) b = mid;
        else a = mid;
    }

    cout << b + s1 << "\n";
    return 0;
}

