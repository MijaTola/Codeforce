#include <bits/stdc++.h>

using namespace std;

int main() {
    int b;
    cin >> b;
    int a = 1;
    int f = 1;
    while(a <= b) {
        if(f) cout << a++ << " ";
        else cout << b-- << " ";
        f = !f;
    }
    cout << "\n";
    return 0;
}

