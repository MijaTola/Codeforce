#include <bits/stdc++.h>

using namespace std;

int n;
map<int,int> mp, ans;
vector<int> v,b;

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
        v.push_back(x);
        b.push_back(x);
    }
    
    sort(v.begin(), v.end());

    if((int)mp.size() == n) {
        for (int i = 0; i < n; ++i) 
            ans[v[i]] = v[(i + 1) % n];
        
        for (int i = 0; i < n; ++i)
            cout << ans[b[i]] << " ";
        cout << "\n";
    } else cout << "-1\n";
    
    
    return 0;
}

