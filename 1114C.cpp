#include <bits/stdc++.h>

using namespace std;

int main() {

    string s = "";

    long long n,b;
    cin >> n >> b;

    long long ans = 1e18;

    for (long long i = 2; i * i <= b; ++i) {
        int cnt = 0;
        while(b % i == 0) { b /= i, cnt++;}
        if(cnt == 0) continue;
        long long cur = 1;
        long long sum = 0;
        while(cur <= n / i) cur *= i, sum += n / cur;
        ans = min(ans, sum / cnt);
    }
    if(b > 1) {
        long long cur = 1;
        long long sum = 0;
        while(cur <= n / b) cur *= b, sum += n / cur;
        ans = min(ans, sum);
    }
    cout << ans << "\n";
    return 0;
}

