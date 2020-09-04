#include <bits/stdc++.h>

using namespace std;

int a[27];

bool f(int pos, int da, int db) {
    if(pos == 27) {
        if(da == db and da and db) cout << da << " " << db << " wtf";
        return da == db and da and db;
    }
    bool ans = 0;
    if(a[pos] == 0) ans |= f(pos + 1, da , db); 
    else if(a[pos] >= 2) {
        ans |= f(pos + 1,da++,db);
        ans |= f(pos + 1,da,db++);
        ans |= f(pos + 1,da++,db++);
    }else {
        ans |= f(pos + 1,da++,db);
        ans |= f(pos + 1,da,db++);
    }
    return ans;
}
int main(){
    
    string s; cin >> s;

    for (int i = 0; i < (int)s.size(); ++i) 
        a[s[i] - 'a']++;
    
    if(f(0,0,0)) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

