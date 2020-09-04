#include <bits/stdc++.h>

using namespace std;

int ans[100010];
int t,n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;  
    while(t--) {
        vector<pair<pair<int,int> ,int> > v;
        memset(ans, 0,sizeof ans);
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int x,y;
            cin >> x >> y;
            v.push_back({{x,y}, i});
        }

        sort(v.begin(), v.end());
        
        int mx = v[0].first.second;
        int p = 0;
        
        while(v[p].first.first <= mx and p < n) {
            mx = max(v[p].first.second,mx);
            p++;
        }

        if(p == n) {
            cout << "-1\n";
            continue;
        }

        for (int i = p; i < n; ++i)
            ans[v[i].second] = 1;

        for (int i = 0; i < n; ++i)
            cout << ans[i] + 1<< " ";
        cout << "\n";
    }
    return 0;
}

