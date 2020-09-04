#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
int c[200010];
int last[200010];
map<int,int> mp;

int main() {
    
    int n,m;
    cin >> n >> m;

    vector<int> a, b(m);
    set<int> s;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        a.push_back(x);
    }
    
    long long ans = 1;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        ans &= s.count(b[i]);
        mp[b[i]] = i;
    }


    int mn = 1e9;
        
    for (int i = n - 1; i >= 0; i--) {
        mn = min(mn, a[i]);
        c[i] = mn;
    }

    for (int i = 0; i < n; ++i) {
        if(mp.count(a[i])) last[mp[a[i]]] = i;
        if(a[i] < b[0]) ans = 0;
    }


    

    for (int i = 0; i < m; ++i) {
        int pos = last[i];
        if(c[pos] < b[i]) ans = 0;
        if(i + 1 >= m) continue;
        int pos2 = last[i + 1];
        int l = pos, r = pos2;

        while(r - l > 1) {
            int mid = (r + l) / 2;
            if(c[mid] < b[i + 1]) l = mid;
            else r = mid;
        }
        
        int df = pos2 - r + 1;

        ans *= df;
        ans %= mod;
    }
    
    
    cout << ans << "\n";
    return 0;
}

