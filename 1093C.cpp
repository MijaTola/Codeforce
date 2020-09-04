#include <bits/stdc++.h>

using namespace std;

long long v[200010];
long long a[200010];

int main() {

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n / 2; i++)
        scanf("%lld", v + i);

    //n - i - 1
    for (int i = 0; i < n / 2; ++i) {
        a[i] = 0;
        a[n - i - 1] = v[i];
    }

    int pos = 1;
    while(pos < n / 2) {
        int l = pos;
        int r = n - pos - 1;
        if(a[r + 1] < a[r]) {
            long long total = a[r];
            a[r] = a[r + 1];
            long long left = abs(total - a[r]);
            a[l] += left;
        }
        if(a[l] < a[l - 1]) {
            long long total = a[l];
            a[l] = a[l - 1];
            long long left = abs(total - a[l]);
            a[r] -= left;
        }
        pos++;
    }

    for (int i = 0; i < n; ++i)
        printf("%lld ", a[i]);
    puts("");


    return 0;
}

