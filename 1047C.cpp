#include <bits/stdc++.h>

using namespace std;

int v[30000010];
int b[30000010];
bool p[15000010];
vector<int> prime;
void init() {
    for (int i = 2; i * i <= 15000000; ++i) {
        if(p[i]) continue;
        for (int j = i + i; j <= 15000000; j += i) 
            p[j] = 1;
    }
    for (int i = 2; i <= 15000000; ++i)
        if(!p[i]) prime.push_back(i);

}
int main() {
    memset(v, 0, sizeof v);
    init();
    int n;
    scanf("%d", &n);
    int g = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        g = __gcd(g, x);
        b[i] = x;
    }
    for (int i = 0; i < n; ++i) 
        v[b[i] / g]++;

    int mx = 0;
    for (int i = 0; i < (int)prime.size(); ++i) {
        int cur = prime[i];
        int sum = 0;
        for (int j = cur; j <= 15000000; j += cur) 
            sum += v[j];
        mx = max(sum,mx);
    }
    if(mx) printf("%d\n", n - mx);
    else puts("-1");
    return 0;
}
