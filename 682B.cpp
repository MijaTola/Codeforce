#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> v(n);

    for (int &x: v) 
        cin >> x;

    sort(v.begin(), v.end());

    int ans = 1;
    for (int i = 0, p = 1; i < n; ++i) {
        if(v[i] >= p) {
            p++;
            ans = p;
        }
    }

    cout << ans << "\n";
    return 0;
}

