#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n >> s;
    int p = 0;
    int c = 1;
    while(p < n) {
        cout << s[p];
        p += c;
        c++;
    }
    cout << "\n";
    return 0;
}

