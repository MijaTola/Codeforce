#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        string a,b;
        cin >> a >> b;
        vector<pair<int,char> > v,vv;
        char last = '?';
        int c = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            if(a[i] == last) c++;
            else {
                if(c) 
                    v.push_back({c, last});
                c = 1;
                last = a[i];
            }
        }
        
        v.push_back({c, last});
        last = '?';
        c = 0;
        for (int i = 0; i < (int)b.size(); ++i) {
            if(b[i] == last) c++;
            else {
                if(c) 
                    vv.push_back({c, last});
                c = 1;
                last = b[i];
            }
        }
        vv.push_back({c, last});

        if((int)vv.size() != (int)v.size()) {
            cout << "NO\n";
            continue;
        }
        
        bool flag = 1;
        for (int i = 0; i < (int)v.size(); ++i) {
            if(v[i].second != vv[i].second) flag = 0;
            if(vv[i].first < v[i].first) flag = 0;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
   return 0;
}

