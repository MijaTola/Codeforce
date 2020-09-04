#include <bits/stdc++.h>

using namespace std;

int dis;
int f(int l, int r) {
    if(l == r) return l;
    int k1 = (r - l + 1) / 2;
    int mid = (l + r) / 2;
    printf("1 %d 1 ", k1);
    for (int i = l; i < l + k1; ++i) 
        printf("%d ", i);
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if(x == dis) return f(l, l + k1 - 1);
    return f(l + k1, r);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        printf("1 %d ", n - 1);
        for (int i = 1; i <= n; ++i) 
            printf("%d ", i);
        printf("\n");
        fflush(stdout);
        scanf("%d", &dis);
        int node = f(2, n);
        printf("1 %d %d ", n - 1, node);
        for (int i = 1; i <= n; ++i)
            if(i != node) printf("%d ", i);

        printf("\n");
        fflush(stdout);
        int ans = 0;
        scanf("%d", &ans);
        printf("-1 %d", ans);
        printf("\n");
        fflush(stdout);

    }
    return 0;
}

