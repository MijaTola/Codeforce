#include <bits/stdc++.h>

using namespace std;

int n;
long long t;
int v[200010];

int bs(int start, int x) {
    int a = start - 1;
    int b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        int total = v[mid] - v[start - 1];
        if(total >= t) b = mid;
        else a = mid;
    }

    return b;
}
int main() {
    scanf("%d %lld", &n, &t);

    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        v[i] = x;
    }
   
    long long ans = 0;
    while(1) {
        int items = 0;
        long long sum = 0;
        long long curt = t;
        for (int i = 1; i <= n; ++i) {
            if(v[i] <= curt) {
                sum += v[i];
                curt -= v[i];
                items++;
            }
        }
        if(!items or !sum) break;
        ans += (long long)(t / sum) * (long long)items;
        t %= sum;
    }
    printf("%lld\n", ans);
    return 0;
}

