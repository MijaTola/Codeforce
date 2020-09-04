#include <bits/stdc++.h>

using namespace std;


bool ver(string s) {
    string x = s;
    reverse(x.begin(), x.end());
    if(x == s) return 1;
    return 0;
}
int main() {

    int t; 
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if(!ver(s)) cout << s << "\n";
        else puts("-1");
    }
    return 0;
}

