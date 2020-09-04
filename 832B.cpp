#include <bits/stdc++.h>

using namespace std;

string a,b,c,d;
int good[27];
int main(){

    cin >> a >> b;

    for (char x: a) 
        good[x - 'a'] = 1;

    bool hv = 0;

    for (char x: b)
        hv |= x == '*';
    int q;
    cin >> q;

    while(q--) {
        cin >> c;
        
        int l = 0, r = c.size() - 1;

        bool flag = 1;

        while(b[l] != '*' and l < (int)c.size() and l < (int)b.size()) {
            if(b[l] != '?') flag &= b[l] == c[l];
            else flag &= good[c[l] - 'a'];
            l++;
        }
        
        int dr = b.size() - 1;
        while(b[dr] != '*' and r >= l and dr > l) {
            if(b[dr] != '?') flag &= b[dr] == c[r];
            else flag &= good[c[r] - 'a'];
            r--;
            dr--;
        }
        flag &= (l >= dr);
        for (int i = l; i <= r; ++i) 
            flag &= !good[c[i] - 'a'];
        
        if(!hv) flag &= l > r and b.size() == c.size();
        puts(flag ? "YES" : "NO");

    }

    return 0;
}

