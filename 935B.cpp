#include <bits/stdc++.h> 
using namespace std;

int main(){
    
    int n; cin >> n;
    string s; cin >> s;
    
    int x = 0; int y = 0;
    int c = 0;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if(s[i] == 'U') y++;
        else x++;
        if(x > y and (c == -1 or c == 0)) {
            ans++;
            c = 1;
        }
        if(y > x and (c == 1 or c == 0)) {
            ans++;
            c = -1;
        }
    }
    cout << ans - 1 << "\n";
    return 0;
}

