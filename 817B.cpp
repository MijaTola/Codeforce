#include <bits/stdc++.h>

using namespace std;

int n;
long long v[300010];

long long c3n(long long x) {
    return (x * (x - 1) * (x - 2)) / 6;
}

long long c2n(long long x) {
    return (x * (x - 1)) / 2;
}

map<int,int> mp,b;
int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        mp[v[i]]++;
    }
    
    sort(v, v + n);
        
    for (int i = 0; i < 3; ++i)
        b[v[i]]++;
    
    long long ans = 1;
    for (auto x: b) {
        if(x.second == 1) ans *= mp[x.first];
        if(x.second == 2) ans *= c2n(mp[x.first]);
        if(x.second == 3) ans *= c3n(mp[x.first]);
    }
    cout << ans << "\n";
    return 0;
}

