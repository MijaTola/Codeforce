#include <bits/stdc++.h>

using namespace std;

int dx[27];
int main(){
    string a,b,c;
    cin >> a >> b >> c;
    
    for (int i = 0; i < (int)a.size(); ++i)
        dx[a[i] - 'a'] = i;
    
    for (int i = 0; i < (int)c.size(); ++i){
        if(isdigit(c[i])) cout << c[i];
        else{
            char l = tolower(c[i]);
            char cur;
            for (int j = 0; j < (int)a.size(); ++j)
                if(a[j] == l){ cur = b[j]; break;}
            if(l == c[i]) cout << cur;
            else cout << (char)(toupper(cur));
        }
    }
    cout << "\n";
    return 0;
}

