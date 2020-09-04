#include <bits/stdc++.h>

using namespace std;

int n,k;
int main() {

    cin >> n >> k;
    
    int l = k - 1;
    int r = abs(n - k);
    cout << 3 * n + min(l,r) << "\n";;
    return 0;
}

