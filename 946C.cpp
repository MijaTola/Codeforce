#include <bits/stdc++.h>

using namespace std;

string s;
int main(){
    cin >> s;
    
    char cur = 'a';
    for (int i = 0; i < (int)s.size() and cur <= 'z'; ++i) {
        if(s[i] <= cur){
            s[i] = cur;
            cur++;
        }
    }
    if(cur <= 'z') return cout << "-1\n",0;
    cout <<s << "\n";
    return 0;
}

