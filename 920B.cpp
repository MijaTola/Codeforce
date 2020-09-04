#include <bits/stdc++.h>

using namespace std;

int ans[1010];
int main() {
    
    int t;
    cin >> t;
    while(t--) {
        memset(ans, 0, sizeof ans);
        priority_queue<pair<int, pair<int,int> > > q;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            q.push({-l,{-i,r}});
        }
        
        int cur = 1;
        while(!q.empty()) {
            int l = -q.top().first;
            int r = q.top().second.second;
            int idx = -q.top().second.first;
            q.pop();
            if(cur <= l) {
                ans[idx] = l;
                cur = l + 1;
            } else {
                if(cur <= r) {
                  ans[idx] = cur;
                  cur++;
                } 
            }

        }
        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}

