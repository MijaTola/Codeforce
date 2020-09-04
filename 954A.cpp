#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    string v; cin >> n >> v;
    
    int ans = 0;

    int pos = 0;
    while(pos < (int)v.size()) {
        ans++;
        if(v[pos] == 'R' and v[pos + 1] == 'U') pos += 2;
        else if(v[pos] == 'U' and v[pos + 1] == 'R') pos += 2;
        else pos++;
    }
    cout << ans << "\n";
    return 0;
}
