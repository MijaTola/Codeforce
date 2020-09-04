#include <bits/stdc++.h>

using namespace std;

int n;
int v[100010];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", v + i);

    sort(v, v + n);
    
    if(v[n - 3] + v[n - 2] <= v[n - 1]) return puts("NO"), 0;

    puts("YES");

    swap(v[n - 1], v[n - 2]);

    for (int i = 0; i < n; ++i)
        printf("%d ", v[i]);
    puts("");
    return 0;
}

