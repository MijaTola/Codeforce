#include <bits/stdc++.h>

using namespace std;

string s;
int main() {

    cin >> s;
    
    int v = 0;
    int h = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '0') {
            cout << 1 << " " << v + 1<< "\n";
            v++;
            v %= 4;
        } else {
            cout << 3 << " " << h + 1 << "\n";
            h = (h + 2) % 4;
        }
    }
    return 0;
}

