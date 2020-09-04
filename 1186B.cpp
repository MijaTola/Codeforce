#include <bits/stdc++.h>

using namespace std;


long long ver(long long mx, long long mn) {
    long long cnt = mx / 2 + (mx & 1);
    long long cur = mn / 3;
    long long left = mn % 3;
    long long ans = cnt  * cur;
    if(left == 1) ans += mx / 3 + (mx % 3 == 2);
    else if(left == 2) ans += mx / 2 + (mx & 1);
    return ans;
}
int main() {

    long long n,m;
    cin >> n >> m;
    
    cout << max(ver(n,m), ver(m, n)) << "\n";
    return 0;
}

