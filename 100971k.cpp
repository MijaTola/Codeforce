#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;

    int l = 0, r = s.size() - 1;

    while(l < r and s[l] == s[r]) l++,r--;

    if(l >= r) {
        cout << "YES\n";
        cout << s.size() / 2 + 1 << "\n";
        return 0;
    }
    string a = "", b = "";

    for (int i = 0; i < (int)s.size(); ++i)
        if(i != l) a += s[i];
    
    string da = a;
    reverse(a.begin(), a.end());
    if(a == da) {
        cout << "YES\n";
        cout << l + 1 << "\n";
        return 0;
    }

    for (int i = 0; i < (int)s.size(); ++i)
        if(i != r) b += s[i];
    
    a = b;
    da = a;
    reverse(a.begin(), a.end());
    if(a == da) {
        cout << "YES\n";
        cout << r + 1 << "\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}

