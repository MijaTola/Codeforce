#include <bits/stdc++.h>

using namespace std;


long long lcm(long long a, long long b){
    return (a * b) / __gcd(a , b);
}
int main(){
    int n;
    scanf("%d",&n);
    long long ans = 0;

    for (int a = n; a >= n - 100 and a >= 1; --a)
        for (int b = a; b >= n - 100 and b >= 1; --b)
            for (int c = b; c >= n - 100 and c >= 1; --c){
                ans = max(ans,lcm(a,lcm(b,c)));
            }

    printf("%lld\n",ans);

    return 0;
}

