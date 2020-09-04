#include <bits/stdc++.h>

using namespace std;

int main() {

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        map<char, int> mp;

        for (char r: s) mp[r]++;   

        int x = 0, y = 0;

        x += -mp['L'];
        x += mp['R'];

        y += -mp['D'];
        y += mp['U'];


        if(x < 0) mp['L'] += x;
        else mp['R'] -= x;


        if(y < 0) mp['D'] += y;
        else mp['U'] -= y;


        string ans = "";

        if(mp['L'] and mp['R'] and mp['U'] and mp['D']) {
            while(mp['L']--) ans += "L";
            while(mp['U']--) ans += "U";
            while(mp['R']--) ans += "R";
            while(mp['D']--) ans += "D";
        } else {
            if(!mp['L'] and !mp['R'] and mp['U'] and mp['D']) 
                ans = "UD";
            
            if(mp['L'] and mp['R'] and !mp['U'] and !mp['D']) 
                ans = "LR";
        }

        cout << ans.size() << "\n";
        cout << ans << "\n";
    }
    return 0;
}

