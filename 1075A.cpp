#include <bits/stdc++.h>

using namespace std;

long long dis(long long x, long long y, long long a, long long b) {
    return abs(x - a) + abs(y - b);
}

int main() {
    long long n;
    cin >> n;
    long long x,y;
    cin >> x >> y;
    long long d1 = dis(1,1,x,y);
    long long d2 = dis(n,n,x,y);
    puts(d1 <= d2 ? "White":"Black");
    return 0;
}

