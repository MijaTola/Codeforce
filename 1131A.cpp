#include <bits/stdc++.h>

using namespace std;

int main() {
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    int dif = abs(a - x);
    long long ans =  (a + 2 * b + 2) + (x + 2 * y + 2);
    if(dif == 0) cout << ans << "\n";
    else cout << ans + dif << "\n";
    return 0; 
}

