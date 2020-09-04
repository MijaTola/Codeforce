#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m;
        cin >> n >> m;
        
        int a1 = (n / 2) * m;
        if(n & 1) 
            a1 += m / 2 + (m & 1);
        
        int a2 = (m / 2) * n;
        if(m & 1) 
            a2 += n / 2 + (n & 1);

        cout << min(a1, a2) << "\n";
    }
    return 0;
}

