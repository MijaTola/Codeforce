#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int a,b; cin >> a >> b;
    int da = min(a,b);
    int db = max(a,b);
    int ans = INT_MAX;
    for (int i = da; i <= db; ++i) {
        int x = abs(da - i);
        int y = abs(i - db);
        int t1 = (x * (x + 1))/2;
        int t2 = (y * (y + 1))/2;
        ans = min(ans,t1 + t2);
    }
    cout << ans << "\n";
    return 0;
}

