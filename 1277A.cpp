#include <bits/stdc++.h>

using namespace std;

int main() {
    
    vector<long long> v;
    for (int i = 1; i < 10; ++i) {
        long long cur = 0;
        for (int j = 0; j < 10; ++j) {
            cur = cur * 10 + i;
            v.push_back(cur);
        }
    }

    sort(v.begin(), v.end());
    
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        
        int p = 0;
        while(v[p] <= n)p++;
        cout << p << "\n";
    }
    return 0;
}

