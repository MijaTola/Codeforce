#include <bits/stdc++.h>

using namespace std;

set<string> mp;
int main(){
    
    int n; 
    cin >> n;

    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        if(mp.count(s)) puts("YES");
        else puts("NO");
        mp.insert(s);
    }
    return 0;
}

