#include <bits/stdc++.h>

using namespace std;

int n;
string s,t;
map<pair<char, char>, int > mp;
map<char,int> a,b;
int main() {
    
    cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; ++i) 
        if(s[i] != t[i]) {
            mp[{s[i], t[i]}] = i;
            a[s[i]] = i;
            b[t[i]] = i;
        } else ans++;
        
   
    for (auto p: mp) {
        char x = p.first.first;
        char y = p.first.second;
        int id = p.second;
        if(mp.count({y,x})) {
            ans += 2;
            cout << n - ans << "\n";
            cout << id + 1 << " " << mp[{y,x}] + 1<< "\n";
            return 0;
        }
    }
    

    for (auto p: a) {
        if(b.count(p.first)) {
            ans++;
            cout << n - ans << "\n";
            cout << p.second + 1 << " " << b[p.first] + 1 << "\n";
            return 0;
        }
    }

    for (auto p: b) {
        if(a.count(p.first)) {
            ans++;
            cout << n - ans << "\n";
            cout << p.second + 1 << " " << a[p.first] + 1 << "\n";
            return 0;
        }
    }
    cout << n - ans << "\n";
    cout << "-1 -1\n";
    return 0;
}

