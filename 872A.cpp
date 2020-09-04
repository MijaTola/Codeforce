#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    vector<int> v(n), b(m);

    for (int &x: v)
        cin >> x;

    for (int &x: b)
        cin >> x;
    
    sort(v.begin(), v.end());
    sort(b.begin(), b.end());

    int a = min(v[0], b[0]);
    int s = max(v[0],b[0]);
 
    for (auto x: v)
        for (auto y: b)
            if(x == y) return cout << x, 0;

    cout << a << s;
    return 0;
}

