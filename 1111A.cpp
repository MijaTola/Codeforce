#include <bits/stdc++.h>

using namespace std;


bool isvowel(char x) {
    return x == 'a' or x =='e' or x == 'i' or x == 'o' or x == 'u';
}
int main() {
    string s,t;
    cin >> s >> t; 
    int n = s.size();
    int m = t.size();
    int v = 0, c = 0, dv = 0, dc = 0;
    if(n != m) return puts("No");
    for (int i = 0; i < n; ++i) {
        if(isvowel(s[i])) v++;
        else c++;
    }
        
    for (int i = 0; i < n; ++i) {
        int c = 0;
        if(isvowel(s[i]))c++;
        if(isvowel(t[i]))c++;
        if(c == 0 or c == 2) continue;
        return puts("No");
    }
    
    
    for (int i = 0; i < m; ++i) {
        if(isvowel(t[i])) dv++;
        else dc++;
    }

    if(c == dc and dv == v) puts("Yes");
    else puts("No");
    return 0;
}

