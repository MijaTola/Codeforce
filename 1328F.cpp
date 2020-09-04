#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,k;
    cin >> n >> k;
    map<int,int> mp;
    
    vector<pair<int,int> > a,b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (auto p: mp) {
        a.emplace_back(p.second, p.first);
        b.emplace_back(p.second, p.first);
    }

    for (int i = 1; i < n; ++i) 
        a[i].first += a[i - 1].first;

    for (int i = n - 2; i >= 0; i--) 
        b[i].first += b[i + 1].first;

    
    
    return 0;
}

