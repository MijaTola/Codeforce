#include <bits/stdc++.h>

using namespace std;

int main() {
    

    int t;
    cin >> t;
    while(t--) {
        int a,b,c,d,k;
        cin >> a >> b >> c >> d >> k;
        int da = a / c + (a % c != 0);
        int db = b / d + (b % d != 0);
        if(da + db > k) cout << "-1\n";
        else cout << da << " " << db << "\n";
    }
    return 0;
}

