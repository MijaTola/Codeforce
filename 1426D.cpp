#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<long long> v(n);
    map<long long, int> mp;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    long long sum = 0;
    int ans = 0;

    mp[0]++;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        if(mp[-sum]) {
            ans++;
            sum = v[i];
            mp.clear();
            mp[0]++;
        }
        mp[-sum]++;
    }

    cout << ans << "\n";

    return 0;
}

