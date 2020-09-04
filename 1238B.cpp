#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int q;
    cin >> q;
    while(q--) {
        int n,r;
        cin >> n >> r;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            s.insert(x);
        }
        stack<int> st;
        for (int y: s)
            st.push(y);
        
        int ans = 0;
        int cur = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(u - cur <= 0) break;
            cur += r;
            ans++;
        }
        cout << ans<< "\n";
    }
    return 0;
}

