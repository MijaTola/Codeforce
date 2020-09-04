#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    vector<int> v(n);

    for (int &x: v)
        cin >> x;

    if(v[0] & 1 and v[n - 1] & 1 and n & 1) cout << "Yes\n";
    else cout << "No\n";
    

    return 0;
}

