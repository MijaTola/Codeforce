#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n,s,k;
        cin >> n >> s >> k;
        set<int> st;
        for (int i = 0; i < k; ++i) {
            int x; 
            cin >> x;
            st.insert(x);
            st.insert(0);
            st.insert(n + 1);
        }
        
        int dx = s;
        int cnt = 0;
        while(dx <= n and st.count(dx))  {
            dx++;
            cnt++;
        }

        if(st.count(dx)) cnt = 1e9;
        dx = s;
        int cnt2 = 0;
        while(dx >= 1  and st.count(dx))  {
            dx--;
            cnt2++;
        }
        
        if(st.count(dx)) cnt2 = 1e9;
        cout << min(cnt, cnt2) << "\n";
    }
    return 0;
}

