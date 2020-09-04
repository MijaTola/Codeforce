#include <bits/stdc++.h>

using namespace std;

map<int,pair<int,int> > mp;
string a[4];
int main() {
    a[0] = "qwertyuiop";
    for (int i = 0; i < (int)a[0].size(); ++i) 
        mp[a[0][i]] = {0,i};
    a[1] = "asdfghjkl;";
    for (int i = 0; i < (int)a[1].size(); ++i) 
        mp[a[1][i]] = {1,i};

    a[2] = "zxcvbnm,./";
    
    for (int i = 0; i < (int)a[2].size(); ++i) 
        mp[a[2][i]] = {2,i};
    char c;
    string s;
    cin >> c >> s;
    int sum = -1;
    if(c == 'L') sum = 1;

    for (int i = 0; i < (int)s.size(); ++i) {
        cout << a[mp[s[i]].first][mp[s[i]].second + sum];
    }
    cout << "\n";
    return 0;
}

