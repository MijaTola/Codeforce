#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,s;
    cin >> n >> s;
    if(n >= s) cout << "1\n";
    else cout << s / n + (s % n != 0) << "\n";
    return 0;
}

