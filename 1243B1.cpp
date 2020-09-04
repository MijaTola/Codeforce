#include <bits/stdc++.h>

using namespace std;

int ds[30], dt[30];
int main() {
    
    int q,n;
    cin >> q;
    string s,t;
    while(q--) {
        cin >> n >> s >> t;
        if(s == t) {
            puts("Yes");
            continue;
        }
        vector<int> v;
        for (int i = 0; i < n; ++i) 
            if(s[i] != t[i]) v.push_back(i);
        

        if(v.size() > 2) {
            puts("No");
            continue;
        }
        
        if(v.size() == 2) {
            swap(s[v[0]], t[v[1]]);
            if(s == t) {
                puts("Yes");
            } else puts("No");
            continue;
        }
        puts("No");
    }   
    return 0;
}

