#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[100010];
int b[100010];

int main() {
    scanf("%d", &m);
    
    for (int i = 0; i < m; ++i)
        scanf("%d", a + i);

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);

    sort(a, a + m);
    sort(b, b + n);
    reverse(b, b + n);

    int ans = 0;

    for (int i = 0; i < n; ++i)
        if(i % (a[0] + 2) < a[0]) 
            ans += b[i];
    
    printf("%d\n", ans);
    return 0;
}

