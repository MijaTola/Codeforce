#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;
    
    vector<int> a;

    long long sum = 0;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum += x;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    sort(a.rbegin(), a.rend());
    if(a[0] + a[1] >= sum) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

