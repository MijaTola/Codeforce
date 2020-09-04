#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int main() {

    
    int n; cin >> n;

    for (int i = 0; i < n / 2; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int mx = n;
    int ans = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        ans += abs(mx - v[i]);
        mx -= 2;
    }

    mx = n - 1;
    int ans1 = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        ans1 += abs(mx - v[i]);
        mx -= 2;
    }
    cout << min(ans, ans1) << "\n";
    return 0;
}

