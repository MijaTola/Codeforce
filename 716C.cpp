#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int k = 1;
    int cur = 2;
    vector<long long> ans;
    while (k <= n) {
        long long  p = k + 1;
        while(p * p < cur or (p * p - cur) % k != 0)
            p += k + 1;

        long long pot = p * p;
        printf("%lld\n",(pot - cur) / k);
        cur = p;
        k++;
    }

    return 0;
}

