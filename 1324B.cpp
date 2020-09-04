#include <bits/stdc++.h>

using namespace std;

int t,x,n;
vector<int> v[5010];

int main() {
    
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        for (int i = 0; i < 5010; ++i)
            v[i].clear();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
        
        bool flag = 0;

        for (int i = 0; i < 5010; ++i) {
            if(v[i].size() < 2) continue;

            int a = v[i][0], b = v[i].back();
            
            flag |= b - a > 1;
        }

        puts(flag ? "YES": "NO");
        
    }
    return 0;
}

