#include <bits/stdc++.h>

using namespace std;

int main() {

    int n; cin >> n;
    int x = n;
    
    while(x % 3 == 0 or (n - x) % 3 == 0 or n - x <= 1) x--;
    for (int i = 1; i <= n - x; ++i) {
        int xx = i;
        int yy = n - x - i;
        if(xx % 3 != 0 and yy % 3 != 0) return cout << xx << " " << yy << " " << n - (xx + yy) << "\n",0;
    }
    return 0;
}

