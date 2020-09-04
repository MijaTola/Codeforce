#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int c = 0;
    for (char x: s)
        c += x == 'a';
    
    int ans = c;
    int sz = s.size();
    while(c <= sz / 2) {
        sz--;
    }
    cout << sz << "\n";

    return 0;

}

