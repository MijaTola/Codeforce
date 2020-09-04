#include <bits/stdc++.h>

using namespace std;

map<char,int> mp;
int main() {
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < (int)s.size(); ++i)
        mp[s[i]]++;

    while(mp['o'] and mp['n'] and mp['e']) {
        cout << 1 << " ";
        mp['o']--;
        mp['n']--;
        mp['e']--;
    }
    
    while(mp['z'] and mp['r'] and mp['o'] and mp['e']) {
        cout << 0 << " ";
        mp['z']--;
        mp['e']--;
        mp['r']--;
        mp['o']--;
    }

    cout << "\n";
            
    return 0;
}

