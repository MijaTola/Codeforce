#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int q;
    cin >> q;

    while(q--) {
        long long a,b,n,s;
        cin >> a >> b >> n >> s;
        long long dv = s / n;
        dv = min(dv, a);
        if(s - dv * n <= b) puts("yes");
        else puts("no");
    }
    return 0;
}

