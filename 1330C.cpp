#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,m;
    cin >> n >> m;

    vector<long long> v(m),b;

    for (auto &x: v) {
        cin >> x;
        b.push_back(x);
    }

    for (int i = m - 2; i >= 0; i--) 
        v[i] += v[i + 1];

    if(v[0] < n) return cout << "-1\n", 0;
    
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if(b[i] + i > n) return cout << "-1\n", 0;
        ans.push_back(max(1LL * i + 1, n - v[i] + 1));
    }

    for (auto x: ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
