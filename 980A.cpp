#include <bits/stdc++.h>

using namespace std;

int main(){
    string s; cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == '-') a++;
        else b++;
    }
    
    if(b and a % b == 0) cout << "YES\n";
    else if((a and !b) or (!a and b)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

