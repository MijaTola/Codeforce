#include <bits/stdc++.h>

using namespace std;

map<string,int> mp;
int main(){
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        mp[x]++;
    }
    for (int i = 0; i < n; ++i) {
        string x; cin >> x;
        mp[x]--;
    }
    
    int ans = 0;
    for (pair<string,int> p: mp) 
        ans += max(0,p.second);

    cout << ans << "\n";

    return 0;
}

