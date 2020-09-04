#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int cnt = 0;
        
        int p = 0;
        stack<char> st;
        while(p < (int)s.size()) {
            if(st.empty() or st.top() == s[p]) {
                st.push(s[p]);
            } else {
                cnt++;
                st.pop();
            }
            p++;
        }
        if(cnt & 1) cout << "DA\n";
        else cout << "NET\n";
    }
    return 0;
}

