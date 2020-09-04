#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    vector<int> v(n), a(n), ans(n);

    for (int &x: v)
        cin >> x;
    
    
    for (int i = 0; i < n; ++i) {
        int l = max(i - v[i], 0);
        a[l]++;
        a[i]--;
    }
    

    int cur = 0;

    for (int i = 0; i < n; ++i) {
        cur += a[i];
        ans[i] = cur;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cnt += ans[i] == 0;

    cout << cnt << "\n";
    return 0;
}

