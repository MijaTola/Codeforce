#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string s;
    cin >> s;
    if(s == "11") return cout << "1\n",0;
    int ans = s.size() / 2;
    bool flag = 0;
    for (int i = 1; i < (int)s.size(); ++i) 
        flag |= s[i] == '1';
    ans += flag and s.size() % 2 != 0;
    cout << ans << "\n";
    return 0;
}

