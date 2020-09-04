#include <bits/stdc++.h>

using namespace std;


bool is(char x) {
    return x == 'a' or x =='e' or x == 'i' or x == 'o' or x == 'u' or x == 'y';
}
int main(){
    int n; cin >> n;
    string s; 
    cin >> s;

    bool found = 1;
    while(found) {
    string ans = "";
    found = 0;
    for (int i = 0; i < (int)s.size(); ++i){
        ans += s[i];
        if(is(s[i]) and is(s[i + 1])) {
            found = 1;
            i++;
        }
    }
    s = ans;
    }
    cout << s << "\n";
    return 0;
}

