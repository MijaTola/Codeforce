#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n,m;
    cin >> n >> m;
    
    v.push_back(0);
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        v.push_back(x);
    }

    for (int i = 1; i <= n; ++i) 
        v[i] += v[i - 1];

    for (int i = 0; i < m; ++i) {
        long long x; cin >> x;
        int pos = lower_bound(v.begin(),v.end(),x) - v.begin();
        cout << pos << " " << x - v[pos - 1] << "\n";
    }
    return 0;
}

