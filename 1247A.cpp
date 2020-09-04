#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,b;
    cin >> a >> b;

    if(a == 9 and b == 1) return puts("9 10"),0;
    if(abs(a - b) > 1 or a > b) return puts("-1"),0;
    if(a == b) cout << a << "0 " << b << "1\n";
    else cout << a << "9" << " " << b << "0\n";
    return 0;
}

