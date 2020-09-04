#include <bits/stdc++.h>

using namespace std;

bool check (int x) {
    for (int i = 2; i * i <= x; ++i)
        if(x % i == 0) return 1;
    return 0;
}

int main() {
    
    int n;
    cin >> n;

    int p = 4;
    while(1) {
        if(check(p) and check(p + n)) {
            return cout << p + n<< " " << p  << "\n", 0;
        }
        p++;
    }
    return 0;
}

