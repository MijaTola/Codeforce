#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    string s; cin >> s;
    int x = 0;
    for (int i = 0; i < (int)s.size(); ++i) 
        if(s[i] == '0') x++;
    
    if(x != (int)s.size())cout << "1";
    for (int i = 0; i < x; ++i)
        cout << "0";
    cout << "\n";
    return 0;
}



