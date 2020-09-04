#include <bits/stdc++.h>

using namespace std;

long long v[100010];
int main() {

    int b,k;
    cin >> b >> k;

    for (int i = 0; i < k; ++i) 
        cin >> v[i];
    
    long long db = 1;
    long long odd = 0;
    long long p = k - 1;

    for (int i = 0; i < k; ++i) {
        int x = v[p] * db;
        p--;
        db *= b;
        if(x & 1) odd++;
    }

    if(odd &  1LL) cout  << "odd\n";
    else cout << "even\n";

    return 0;

}

