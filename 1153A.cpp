#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,t;
    cin >> n >> t;
    vector<pair<long long,int> > v;
    for (int i = 0; i < n; ++i) {
        int s,d;
        cin >> s >> d;
        
        while(s < t) s += d;

        v.push_back({s,i});
    }
    sort(v.begin(), v.end());
    cout << v[0].second + 1 << "\n";
    return 0;
}

