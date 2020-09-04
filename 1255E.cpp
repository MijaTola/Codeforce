#include <bits/stdc++.h>

using namespace std;

vector<int> pr;
int is[1000010];

int main() {
    
    for (int i = 2; i < 1000010; ++i) {
        if(is[i]) continue;   
        for (int j = i + i; j < 1000010; j += i) 
            is[j] = 1;
    }

    for (int i = 2; i < 1000010; ++i)
        if(!is[i]) pr.push_back(i);
    
    int n;
    scanf("%d", &n);
    vector<long long> v(n);

    for (auto &x: v) 
        scanf("%lld", &x);
    
    long long sum = 0;

    for (int i = 0; i < n; ++i)
        sum += v[i];
    
    if(sum == 1) return puts("-1"), 0;

    vector<long long> dv;
    for (auto x: pr)
        if(sum % x == 0)
            dv.push_back(x);

    dv.push_back(sum);
    long long ans = LLONG_MAX;

    for (auto k: dv) {
        vector<long long> b = v;
        long long cans = 0;
        long long cur = 0;

        for (int i = 0; i < n - 1; ++i) {
            cur += b[i];
            long long x = k - cur % k;
            long long y = cur % k;
            
            if(y < x) {
                b[i + 1] -= y;
                cur += y;
                cans += y;
            } else {
                cans += x;
                cur -= x;
                b[i + 1] += x;
            }
        }

        //cout << k << ": " << cans << "\n";

        ans = min(ans, cans);
    }

    printf("%lld\n", ans);
    return 0;
}

