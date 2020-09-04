#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    string s; cin >> n >> s;
    int mx = 0;

    for (int i = 0; i <= (int)s.size() / 2; ++i) {
        string a = s.substr(0,i);
        string b = s.substr(i, i);
        if(a == b) mx = i;
    }
    cout << s.size() - mx + (mx != 0) << "\n";
    return 0;
}
 
