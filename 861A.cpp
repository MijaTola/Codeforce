#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    int k;
    scanf("%lld %d",&n,&k); 

    long long ans = LLONG_MAX;
    
    long long p = 1LL;

    for (int i = 0; i < k;++i)
        p *= 10LL;
    
    long long lcm = (n * p) / __gcd(n,p);
    printf("%lld\n",lcm);
    return 0;
}

