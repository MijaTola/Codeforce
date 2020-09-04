#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin,s);
    
    int mx = -1;
    int cur = 0;
    for (int i = 0; i < (int)s.size(); ++i){
        if(s[i] == ' ') cur = 0;
        if(s[i] >= 'A' and s[i] <= 'Z') cur++;
        mx = max(cur,mx);
    }
    cout << mx << "\n";
    return 0;
}

