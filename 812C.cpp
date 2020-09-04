#include <bits/stdc++.h>

using namespace std;

int n,s;
long long cur;
int v[100010];
long long ac[100010];
bool ver(int k){
    for (int i = 0; i < n; ++i)
        ac[i] = v[i] + (long long)(i + 1)*k;
    
    sort(ac,ac+n);
    cur = 0;
    for (int i = 0; i < k; ++i)
        cur += ac[i];
    return cur <= s;
}

int main(){
    
    scanf("%d %d",&n,&s);

    for (int i = 0; i < n; ++i)
        scanf("%d",v+i);


    long long a = 0; 
    long long b = n+1;

    while(b - a > 1){
        int mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }
    ver(a);
    printf("%lld %lld\n",a,cur);
    return 0;
}





