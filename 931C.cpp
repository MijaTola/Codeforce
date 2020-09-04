#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n), ans, ans2;;
    int mx = -1e9, mn = 1e9;

    for (int &x: v) {
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
        ans.push_back(x);
        ans2.push_back(x);
    }
        
    vector<int> a,b,c;

    for (int i = 0; i < n; ++i) {
        if(v[i] == mx) a.push_back(i);
        else if(v[i] == mn) b.push_back(i);
        else c.push_back(i);
    }
    
    for (int i = 0; i < (int)min(a.size(), b.size()); ++i) {
        int x = a[i], y = b[i];
        ans[x]--;
        ans[y]++;
    }

    for (int i = 0; i < (int)c.size(); i += 2) {
        if(i + 1 < (int)c.size()) {
            int x = c[i];
            int y = c[i + 1];
            ans2[x]++;
            ans2[y]--;
        }
    }

    sort(ans.begin(), ans.end());
    sort(ans2.begin(), ans2.end());
    sort(v.begin(), v.end());

    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
        if(ans[i] == v[i]) cnt++;
        if(ans2[i] == v[i]) cnt2++;
    }   

    if(cnt < cnt2) {
        cout << cnt << "\n";
        for (int x: ans)
            cout << x << " ";
        cout << "\n";
    } else {
        cout << cnt2 << "\n";
        for (int x: ans2)
            cout << x << " ";
        cout << "\n";
    }

    
   
    return 0;
}

