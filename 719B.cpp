#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    string s;
    cin >> n >> s;

    auto f = [&] (char start) {
        
        int r = 0, b = 0;
        for (int i = 0; i < n; ++i) {
            if(s[i] != start) {
                if(s[i] == 'r')r++;
                else b++;
            }
            if(start == 'r') start = 'b';
            else start = 'r';
        }

        int mn = min(r,b);
        r -= mn;
        b -= mn;
        return mn + r + b;
    };

    cout << min(f('r'), f('b')) << "\n";
    return 0;
}

