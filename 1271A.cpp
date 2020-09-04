#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;

    
    int ans = 0;
    for (int i = 0; i <= d; ++i) {
        int da = i;
        int db = d - i;
        ans = max(min(da, a) * e + min(c,min(db,b)) * f, ans);
    }
    
    cout << ans << "\n";
    return 0;
}

