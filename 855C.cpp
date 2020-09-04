#include <bits/stdc++.h>

using namespace std;

int v[100010];
int main(){
    
    int n,p,q,r;
    scanf("%d%d%d%d",&n,&p,&q,&r);
    for (int i = 0; i < n; ++i)
        scanf("%d",v + i);

    sort(v,v + n);

    
    long long ans = (p > 0) ? p * v[n - 1];
    return 0;
}

