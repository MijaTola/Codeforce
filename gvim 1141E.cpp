#include <bits/stdc++.h>

using namespace std;

int v[200010];

int main() {
    long long h;
    int n;
    cin >> n;

    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }

    long long a = 0;
    long long b = 1e12;

    while(b - a > 1) {
        long long mid = (a + b) / 2;
        if(mid * sum <= 0) b = mid;
        else a = mid;
    }
    return 0;
}

