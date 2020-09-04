#include <bits/stdc++.h>

using namespace std;

bool p[1000010];
vector<int> primes;
void criba() {
    memset(p, 0, sizeof p);
    for (int i = 2; i * i < 1000100; ++i) {
        if(p[i]) continue;
        for (int j = i + i; j < 1000010; j += i)
            p[j] = 1;
    }
    for (int i = 2; i < 1000010; ++i)
        if(!p[i]) primes.push_back(i);
}

long long f(long long n) {
    long long ans = 0;
    int pos = 0;
    int pf = primes[0];
    bool flag = 0;
    while(pf * pf <= n and pos < (int)primes.size()) {
        while(n % pf != 0) {
            if(pos + 1 < (int)primes.size())pf = primes[++pos];
            else {
                flag = 1;
                break;
            }
        }
        if(flag) break;
        n -= pf;
        ans++;
        if(n % 2 == 0) {
            ans += n / 2;
            n = 0;
            break;
        }
    }
    if(n != 1 and n) ans++;
    return ans;
}

int main() {
    criba();
    long long n;
    scanf("%lld", &n);    
    printf("%lld\n", f(n));
    return 0;
}

