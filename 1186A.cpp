#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n,m,k;
    cin >> n >> m >> k;

    if(min(m,k) >= n) puts("YES");
    else puts("NO");
    return 0;
}

