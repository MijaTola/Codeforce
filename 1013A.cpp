#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a += x;
    }

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        b += x;
    }

    if(a >= b) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

