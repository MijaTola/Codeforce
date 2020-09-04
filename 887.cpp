#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;

    bool f = 0;

    int c = 0;

    for (int i = s.size() -1; i >= 0; --i){
        if(s[i] == '0') c++;
        if(s[i] == '1' and c >= 6) f=1;
    }
    
    cout << (f ? "yes": "no");
    /*if(s.size() <= 6) return puts("no"),0;
    
    bool f = 0;
    int i;
    for (i = 0; i < (int)s.size() - 6; ++i){
        if(s[i] == '1'){f = 1; break;}
    }
    
    int c = 0;
    for (; i < (int)s.size(); ++i){
        if(s[i] == '0') c++;
    }
    
    if(!f) return puts("no"),0;
    else if(c >= 6) puts("yes");
    else puts("no");*/
    return 0;
}
