#include <bits/stdc++.h>

using namespace std;

int n;
int is[1000010];
int v[1010];
int main(){

    scanf("%d",&n);
    
    int g = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", v + i);
        is[v[i]] = 1;
        g = __gcd(g, v[i]);
    }

    if(!is[g]) return cout << "-1\n", 0;

    printf("%d\n", 2 * n - 1);
    
    printf("%d ", v[0]);
    for (int i = 1; i < n; ++i) 
        printf("%d %d ", v[0], v[i]);
    
    puts("");


    return 0;
}

