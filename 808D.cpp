#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main(){
    
    int n; scanf("%d",&n);
    
    long long sum = 0LL;
    for (int i = 0; i < n; ++i){
        scanf("%d",v+i);
        sum += v[i];
    }
    if(sum&1) return puts("NO"),0;
    sum /= 2;
    int da,db; da = db = 0;
    sort(v,v+n); reverse(v,v+n);
    for (int i = 0; i < n; ++i){
        if(da < db) da += v[i];
        else db += v[i];
    }
    if(da == db) puts("YES");
    else puts("NO");
    return 0;
}

