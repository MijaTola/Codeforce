#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n,m;
    cin >> n >> m;
    
    double ans = 1e9;
    for (int i = 0; i < n; ++i) {
        double a,b;
        cin >> a >> b;
        double cur = a / b;
        ans = min(ans, cur * m);
    }
    cout.precision(10);
    cout << fixed << ans << "\n";
    return 0;
}

