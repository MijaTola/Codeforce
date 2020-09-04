#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k,s,t;
    cin >> n >> k >> s >> t;
    
    vector<pair<int,int> > v;
    vector<int> a;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.emplace_back(y,x);
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }


    a.push_back(s);
    sort(a.begin(), a.end());

    auto ver = [&](int k) -> long long {
        int ini = 0;
        long long tm = 0;
        for (int x: a) {
            long long dis = x - ini;
            int l = -1, r = dis;
            while(r - l > 1) {
                int mid = (r + l) / 2;
                int no = mid, ac = dis - mid;
                if(no + 2 * ac <= k) r = mid;
                else l = mid;
            }
            long long no = r, ac = dis - r;
            if(no + 2 * ac <= k)  tm += 2 * no + ac;
            else return 0;
            ini = x;
        }
        return tm <= t;
    };
    
    int l = -1, r = n;
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if(ver(v[mid].first)) r = mid;
        else l = mid;
    }

    
    long long ans = 1e15;

    for (int i = r; i < n; ++i)
        ans = min(ans, 1ll*  v[i].second);

    if(ans == 1e15) cout << "-1\n"; 
    else cout << ans << "\n";

    return 0;
}

