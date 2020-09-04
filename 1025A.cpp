#include <bits/stdc++.h>

using namespace std;

int v[30];
int main(){
    memset(v, 0, sizeof v);
    int n; cin >> n;
    string s; cin >> s;
    if(n == 1) return cout << "Yes\n",0;
    for (int i = 0; i < (int)s.size(); ++i) 
        v[s[i] - 'a']++;
    for (int i = 0; i < 30; ++i)
        if(v[i] >= 2) return cout << "Yes\n",0;
    cout << "No\n";
    return 0;
}

