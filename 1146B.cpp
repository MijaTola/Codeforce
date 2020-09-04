#include <bits/stdc++.h>

using namespace std;

int v[100010];

int main() {
 
    
    string s;
    cin >> s;
    
    for (int i = 0; i < (int)s.size(); ++i)
        v[i] = s[i] == 'a';
    
    for (int i = s.size() - 1; i >= 0; i--) {
        v[i] += v[i + 1];
    }
    

    int c = 0;
    int id = -1;
    for (int i = 0; i < (int)s.size(); ++i) {
        c += s[i] != 'a';
        if(v[i + 1] > 0) continue;
        int sz = s.size() - i;
        int r = sz - v[i + 1];
        if(c == r - 1) {
            id = i;
            break;
        }
    }

    if(c == 0) return cout << s << "\n", 0;
    
    if(id == -1) return cout << ":(\n", 0;

    string a = "";
    string b = "";
    for (int i = 0; i <= id; ++i) 
        if(s[i] != 'a')a += s[i];

    for (int i = id + 1; i < (int)s.size(); ++i)
        b += s[i];
    if(a != b) return cout << ":(\n",0;

    for (int i = 0; i <= id; ++i)
        cout << s[i];
    cout << "\n";

    return 0;
}

