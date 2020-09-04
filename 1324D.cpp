#include <bits/stdc++.h>

using namespace std;

bool cmp (pair<int,int> a, pair<int,int> b) {
    return a.first + a.second < b.first + b.second;
}

int n;

int main() {
    
    cin >> n;
    vector<int> v(n), b(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
        cin >> b[i];

    for (int i = 0; i < n; ++i) {
        int a =v[i], bb = b[i];
        v[i] = a - bb;
        b[i] = bb - a;
    }

    sort(v.begin(), v.end());
    sort(b.begin(), b.end());
    long long ans = 0;
    for (int x: v) {
        int pos = lower_bound(b.begin(), b.end(), x) - b.begin();
        int cur = 1;
        if(x <= 0) cur = 0;
        ans += pos - cur;
    }

    cout << ans / 2<< "\n";


    
    
    return 0;
}

