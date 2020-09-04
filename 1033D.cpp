#include <bits/stdc++.h>
using namespace std;

long long v[510];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%lld",v + i);
    map<long long, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if(v[i] == v[j]) continue;
            if(__gcd(v[i],v[j]) == 1) continue;
            long long cur = __gcd(v[i],v[j]);
            while(v[i] % cur == 0) v[i] /= cur;
            while(v[j] % cur == 0) v[j] /= cur;
        }
    }

    for (int i = 0; i < n; ++i) 
        if(v[i] != 1) mp[v[i]]++;
    
    long long ans = 1;
    for (auto e: mp) {
        cout << e.first << " " << e.second << "\n";
        ans *= (e.second + 1);
    }
    printf("%lld\n",ans);
    
    return 0;
}
