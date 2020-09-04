#include <bits/stdc++.h>

using namespace std;

bool is(char x) {
    return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u';
}

int main(){
    
    string s; cin >> s;

    
    for (int i = 0; i < (int)s.size(); ++i) {
        if(!is(s[i]) and !is(s[i + 1]) and s[i] != 'n') return cout << "NO",0;
    }

    cout << "YES";
    return 0;
}

