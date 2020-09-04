#include <bits/stdc++.h>

using namespace std;

int main() {

    string s = "";

    int n,b;
    cin >> n >> b;

    while(n > 0) {
        s += (char)((n % b) + '0');
        n /= b;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}

