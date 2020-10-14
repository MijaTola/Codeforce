#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    vector<pair<int,int> > v(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i].first;

    for (int i = 0; i < n; ++i)
        cin >> v[i].second;

    
    long long ans = 0;
    long long cur = 0;

    long long last = -1;

    for (int i = 0; i < n; ++i) {
        if(v[i].first == last) {
            cur += v[i].second;
        } else {
            ans = max(ans, cur);
            cur = v[i].second;
        }
        last = v[i].first;
    }
            
    cout << ans << "\n";

    return 0;
}

