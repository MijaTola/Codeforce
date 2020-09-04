#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> v(n);

    for (int &x: v)
        cin >> x;

    sort(v.begin(), v.end());
    
    cout << v[(n - 1) / 2] << "\n";
    return 0;
}

