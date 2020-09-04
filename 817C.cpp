#include <bits/stdc++.h>

using namespace std;

long long n,s;

 long long ver(unsigned long long x) {
    int sum = 0;
    long long y = x;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return (long long)y - sum;
}
int main() {
    cin >> n >> s;

    unsigned long long a = 0, b = n + 1;

    while(b - a > 1) {
        unsigned long long mid = (a + b) / 2;
        if(ver(mid) < s) a = mid;
        else b = mid;
    }
    cout << n - b + 1 << "\n";
    return 0;
}

