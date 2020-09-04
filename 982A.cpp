#include <bits/stdc++.h>

using namespace std;

int n; 
string s; 

bool ver(int id) {
    if(id == 0) return s[id + 1] == '0';
    if(id + 1 == n) return s[id - 1] == '0';
    return s[id + 1] == '0'  and s[id - 1] == '0';
}
int main(){
    cin >> n >> s;

    int mx = (n + 1) / 2;
    if(n == 1 and s[0] == '0') goto isnot;
    for (int i = 1; i < n; ++i) {
        if(s[i] == '1' and s[i] == s[i - 1]) goto isnot;
    }

    for (int i = 0; i < n; ++i) 
        if(s[i] == '0' and ver(i)) goto isnot;
    
    cout << "Yes\n";
    return 0;

    isnot:
        cout << "No\n";
    return 0;
}

