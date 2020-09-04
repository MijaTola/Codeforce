#include <bits/stdc++.h>

using namespace std;

int da[27];
int db[27];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        memset(db, 0, sizeof db);
        memset(da, 0, sizeof da);
        string a,b;
        cin >> a >> b;
        for (char x: a)
            da[x - 'a']++;

        for (char x: b)
            db[x - 'a']++;

        bool flag = 0;
        for (int i = 0; i < 27; ++i) 
            flag |= da[i] and db[i];
        puts(flag ? "YES":"NO");
    }
    return 0;
}

