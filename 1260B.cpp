#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        if((a + b) % 3 == 0 and 2 * a >= b) puts("YES");
        else puts("NO");
    }
    return 0;
}

