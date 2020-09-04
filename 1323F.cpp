#include <bits/stdc++.h>

using namespace std;

int n,m,x;
int l[2010];
int s[2010];
int c[5010];

int main() {
    
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
        scanf("%d", l + i);

    for (int i = 1; i <= n; ++i)
        scanf("%d", s + i);

    for (int i = 1; i <= n + m; ++i) 
        scanf("%d", c + i);


    return 0;
}

