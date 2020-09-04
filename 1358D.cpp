#include <bits/stdc++.h>

using namespace std;

long long v[1000010];
long long s[1000010];
long long d[1000010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    long long x;
    cin >> n >> x;

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        v[i + n] = v[i] = d[i + n] = d[i];
        s[i] = s[i + n] = (v[i] * (v[i] + 1)) / 2;
    }

    for (int i = 1; i < 2 * n; ++i) {
        v[i] += v[i - 1];
        s[i] += s[i - 1];
    }

    long long ans = 0;

    for (int i = n; i < 2 * n; ++i) {
        int a = 1, b = i + 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            long long ac = v[i] - v[mid - 1];
            if(ac <= x) b = mid;
            else a = mid;
        }
        
        long long cur = v[i] - v[b - 1];
        long long current = s[i] - s[b -  1];
        long long left = x - cur;
        long long val = d[b - 1];
        long long sum = (val * (val + 1) / 2);
        long long nn = val - left;
        long long ss = nn * (nn + 1) / 2;
        current += sum - ss;
        ans = max(ans, current);
    }

    cout << ans << "\n";

    return 0;
}

