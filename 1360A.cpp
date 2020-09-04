#include <bits/stdc++.h>

using namespace std;

int main() {


    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;

        int mn = min(a,b);
        int mx = max(a,b);
        if(mn + mn >= max(a,b)) {
            cout << (mn + mn) * (mn + mn) << "\n";
        } else {
            cout <<  mx * mx<< "\n";
        }
    }
    return 0;
}

