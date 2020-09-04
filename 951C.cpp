#include <bits/stdc++.h>

using namespace std;

long long a,b;
long long n[10];

//956
//590
//569

long long count(long long x){
    memset(n,0,sizeof n);
    long long p = 1LL;   
    while(x > 0) {
        int m = x % 10LL;
        x /= 10LL;
        n[m]++;
        if(x > 0) p *= 10LL;
    }
    return p;
}

bool ver() {
    for (int i = 0; i < 10; ++i)
        if(n[i]) return 1;
    return 0;
}

long long gen(long long x, int d, long long p) {
    for (int i = 0; i < 10; ++i) {
        int f = 0;
        if(i == d) f = 1;
        for (int j = 0; j < (n[i] - f); j++) {
            x += (p * i);
            p /= 10LL;
        }
    }
    return x;
}
int main(){
    
    scanf("%lld %lld",&a,&b);
    
    long long p = count(a);
    long long pos = 9LL;
    long long ans = 0LL;
    while(ver() and pos >= 0) {
        if(!n[pos]){ pos--; continue; }
        long long cur = (long long) (p * pos) + ans;
        
        long long cur2 = gen(cur, pos, p / 10LL);
        if(cur2 < p) { pos--;continue; }
        if(cur2 > b) { pos--;continue; }
        ans = cur;
        n[pos]--;
        p/=10LL;
        pos = 9LL;
    }
    printf("%lld\n",ans);
    return 0;
}



