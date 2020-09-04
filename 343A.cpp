#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long a,b;
    scanf("%lld %lld",&a,&b);
    
    long long ans = 0LL;
    while(b != 0){
        long long cur = b;
        ans += a / b;
        b = a % b;
        a = cur;
    }
    printf("%lld\n",ans);
    return 0;
}

