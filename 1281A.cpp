#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        
        if(s[s.size() - 2] == 'p' and s[s.size() - 1] == 'o') {
            cout << "FILIPINO\n";
            continue;
        }


        string x = s.substr(s.size() - 4, s.size());
    
        if(x == "desu" or x == "masu") {
            cout << "JAPANESE\n";
            continue;
        }

        cout << "KOREAN\n";
    }
    return 0;
}

