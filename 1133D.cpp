#include <bits/stdc++.h>

using namespace std;

int a[200010];
int b[200010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> a[i];
    for (int i = 0; i < n; ++i) 
        cin >> b[i];
    
    map<pair<bool,pair<int,int> > ,int> mp;

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int db = b[i];
        int da = a[i];
        if(da == 0 and db == 0) cnt++;
        if(!a[i]) continue;
        int g = __gcd(da,db);
        mp[make_pair(!((long long)db * da > 0),
                make_pair(abs(db / g),abs(da / g)))]++;
    }

    int ans = 0;
    for (auto x: mp) 
        ans = max(x.second,ans);
    cout << ans + cnt << "\n";
    return 0;
}

