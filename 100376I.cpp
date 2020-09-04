#include <bits/stdc++.h>

using namespace std;

int n,a,b,v[1000010];
int main() {
    scanf("%d %d %d", &n, &a, &b);
    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    long long sum = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        ans = max(ans, sum);
        sum = max(sum, 0ll);
    }
    
    printf("%lld\n", (long long)ans * a + b);
    return 0;
}
