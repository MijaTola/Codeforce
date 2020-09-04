#include <bits/stdc++.h>

using namespace std;

int v[200010];
bool vis[200010];
int ans[200010];

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i <= n; ++i)
            vis[i] = 0;

        for (int i = 0; i < n; ++i) 
            cin >> v[i];

        set<int> s;
        
        for (int i = 1; i <= n; ++i) 
            s.insert(i);

        int last = -1;
        for (int i = 0; i < n; ++i) {
            if(v[i] > last) {
                ans[i] = v[i];
                s.erase(v[i]);
            } else {
                if(*s.begin() > last) goto noans;
                ans[i] = *s.begin();
                s.erase(ans[i]);
            }
            
            last = max(last, v[i]);
        }
        
        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << "\n";
        continue;
        noans:
        cout << "-1\n";

    }
    return 0;
}

