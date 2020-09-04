#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i)
        scanf("%d",v + i);

    for (int i = 1; i < n; ++i)
        v[i] += v[i - 1];

    int ans = 0;

    for (int i = 0; i < n-1; ++i)
        if(v[i] == v[n-1] - v[i]) ans++;

    printf("%d\n",ans);
    return 0;
}

