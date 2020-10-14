#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<long long > v(n);
        for (auto &x: v)
            cin >> x;

        sort(v.begin(), v.end());

        long long mx = v.back();
        v.pop_back();

        while(k--) {
            mx += v.back();
            v.pop_back();
        }
        cout << mx << "\n";
    }
    return 0;
}

