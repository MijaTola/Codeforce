#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;
        int dv = n / k;
        int j = min(m, dv);
        int left = m - j;
        int a = left / (k - 1);
        if(left % (k - 1) != 0) a++;
        //cout << j << " " << a << "\n";
        cout << j - a << "\n";
    }

    return 0;
}

