#include <bits/stdc++.h>

using namespace std;

int n,k;
char v[1000];
int main(){
    cin >> n >> k;
    string t; 
    cin >> t;

    int ini = 0;
    for (int i = 0; i <= (int)t.size() - 1; ++i) {
        string l = t.substr(0,i);
        string r = t.substr(t.size() - i, t.size());
        if(l == r) {
            ini = i;
        }
    }

    string ans = t.substr(ini,t.size());
    cout << t;
    k--;
    while(k--) 
        cout << ans;
    cout << "\n";
    return 0;
}

