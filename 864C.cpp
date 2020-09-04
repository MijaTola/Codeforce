#include <bits/stdc++.h>

using namespace std;

long long a,b,f,k;

long long ver(long long x){
    if(x & 1) return x * a + abs((a - f));
    return x * a + f;
}
long long bs(long long ini, long long w){
    long long da = ini;
    long long db = k + 1;
    while(db - da > 1){
        long long mid = (da + db) / 2;
        if(mid * a == a*k and ini * a + w >= mid * a) return k;
        if(ver(mid) <= ini * a + w) da = mid;
        else db = mid;
    }
    return da;
}
int main(){
    
    scanf("%lld%lld%lld%lld",&a,&b ,&f,&k);
    
    int pos = 0;
    long long g = b;
    long long ans = 0;
    while(pos < k){
        pos = bs(pos,g);
        long long nxt = ver(pos);
        if(pos >= k) break;
        if(g >= nxt - pos * a and b >= (pos + 1) * a - nxt){
            g =  b - ((pos + 1) * a - nxt);
            pos++;
        }else return puts("-1");
        ans++;
    }
    printf("%lld\n",ans);
    return 0;
}

