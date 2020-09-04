#include <bits/stdc++.h>

using namespace std;

int main() {

    int x; cin >> x;

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= x; ++j) {
            if(i % j == 0 and i * j > x and i / j < x) {
                return cout << i << " " << j << "\n",0;
            }
            
        }
    }
    cout << "-1\n";
    return 0;
}

