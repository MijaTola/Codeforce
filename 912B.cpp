#include <bits/stdc++.h>

using namespace std;
    
long long n,k;

int main(){
    
    scanf("%lld %lld", &n, &k);
    long long ans = 1LL;
    while(ans <= n) ans *= 2LL;
    if(k == 1) printf("%lld\n", n);
    else printf("%lld\n",ans - 1LL);
    return 0;
}

