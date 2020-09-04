#include <bits/stdc++.h>

using namespace std;

int n;
long long t;
int v[200010];
long long c[200010];
int main() {
    scanf("%d %lld", &n, &t);

    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        c[i] = v[i];
        if(i) c[i] += c[i - 1];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int a = i - 1;
        int b = n - 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(c[mid] - c[i - 1] < t) a = mid;
            else b = mid;
        }
        if(a < i) continue;
        ans += (b - i + 1);
    }
    printf("%lld\n", ans);
    return 0;
}

