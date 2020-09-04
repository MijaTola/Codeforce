#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<pair<int,int> > v;
        int ini = 1e9;
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            v.emplace_back(x,y);
            ini = min(ini, y);
        }

        sort(v.begin(), v.end());
        
        
        int mx = ini;
        for (int i = 1; i < n; ++i)
            if(v[i].first > ini) 
                mx = max(mx, v[i].first);
            

        cout << mx - ini << "\n";

       
    }
    return 0;
}

