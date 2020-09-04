#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    cin >> n >> s;
    bool flag = 1;
    int id = -1;
    for (int i = 0; i < n; ++i) {
        if(s[i] > s[i + 1] and flag) {
            flag = 0;
            id = i;
        } else {
            cout << s[i];
        }
    }
    if(flag and id != n - 1) cout << s[n - 1];
    
    puts("");
    return 0;
}

