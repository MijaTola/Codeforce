#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i){
        int p = s[i] - '0';
        if(s[i] == 'a' or s[i] =='e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
            ans++;
        if(p & 1 and isdigit(s[i])) ans++;
    }
    cout << ans << "\n";
    return 0;
}

