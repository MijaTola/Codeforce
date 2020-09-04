#include <bits/stdc++.h>

using namespace std;

int n;
int v[2010];

bool ver(int sz) {
    set<int> s;
    map<int,int> mp;
    for (int i = sz; i < n; ++i) {
        s.insert(v[i]);
        mp[v[i]]++;
    }
    if((int)s.size() == n - sz) return 1;
    int ini = 0;
    for (int i = sz; i < n; ++i) {
        mp[v[i]]--;
        if(mp[v[i]] == 0)s.erase(v[i]);
        s.insert(v[ini]);
        mp[v[ini++]]++;
        if((int)s.size() == n - sz)return 1;
    }
    return 0;
}

int main() {
    
    cin >> n;
    for (int i = 0; i < n; ++i) 
        cin >> v[i];
    
    int a = -1, b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(ver(mid)) b = mid;
        else a = mid;
    }
    cout << b << "\n";
    return 0;
}

