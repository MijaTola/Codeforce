#include <bits/stdc++.h>

using namespace std;

map<string,string> mp;
map<string,bool> mp2;
int main(){
    
    mp["purple"] = "Power";
    mp["green"] = "Time";
    mp["blue"] = "Space";
    mp["orange"] = "Soul";
    mp["red"] = "Reality";
    mp["yellow"] = "Mind";

    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        mp2[mp[x]] = 1;
    }
    
    int c = 0;
    for (pair<string,string > p: mp) {
        if(!mp2[p.second]) {
            c++;
        }
    }
    cout << c << "\n";

    for (pair<string,string > p: mp) {
        if(!mp2[p.second]) {
            cout << p.second << "\n";
        }
    }
    return 0;
}

