#include <bits/stdc++.h>

using namespace std;

int v[121000];
vector<long long> b;
int main(){

    long long p = 1;
    while(p <= 1e10) {
        b.push_back(p);
        p <<= 1LL;
    }

    int n; cin >> n;   
    for (int i = 0; i < n; ++i) cin >> v[i];
    if(n == 1) return cout << "1\n",0;
    
    sort(v, v + n);
    
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        long long x = v[i];
        bool flag = 0;
        for (int j = 0; j < (int)b.size(); ++j) {
            long long y = abs(b[j] - x);
            int pos = lower_bound(v,v + n, y) - v;
            if(pos == i) pos++;
            flag |= (v[pos] + v[i] == b[j]);
        }
        if(!flag) ans++;
    }
    cout << ans << "\n";
    return 0;
}

