#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v[1010];

int main() {
    
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x % m].push_back(x);;
    }
    
    long long ans = 1;

    for (int i = 0; i < 1010; ++i) {
        if(!v[i].size()) continue;
        if((int)v[i].size() > 1) ans = 0;
        for (int j = i + 1; j < 1010; ++j) {
            if(!v[j].size())  continue;
            if((int)v[j].size() > 1) ans = 0;
            int val = abs(v[i][0] - v[j][0]);
            ans = (ans * val) % m;
        }
    }

    cout << ans << "\n";
    return 0;
}

