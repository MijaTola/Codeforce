#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; 
    string a,b;
    cin >> n >> a >> b;

    int ans = 0;
    for (int i = 0; i < n / 2; ++i) {
        map<char,int> mp;
        mp[a[i]]++;
        mp[b[i]]++;
        mp[a[n - i - 1]]++;
        mp[b[n - i - 1]]++;
        
        if((int)mp.size() == 4) ans += 2;
        if((int)mp.size() == 3) ans += 1 + (a[i] == a[n - i - 1]);
        if((int)mp.size() == 2) {
            set<int> s;
            for (auto x: mp) s.insert(x.second);
            if(s.size() == 2) ans++;
        }
    }
    
    if(n & 1) ans += b[n / 2] != a[n / 2];
    
    cout << ans << "\n";
   
    return 0;
}

