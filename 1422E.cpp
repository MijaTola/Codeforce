#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    cin >> s;

    stack<char> st;

    for (int i = 0; i < (int)s.size(); ++i) {
        st.push(s[i]);
        while((int)st.size() >= 2) {
            auto a = st.top();
            st.pop();
            auto b = st.top();
            st.pop();
            char cur = 'a';
            if(st.size()) cur = st.top();

            if(a == b and (cur > s[i + 1] or cur + 1 == (int)s.size())) {
            } else {
                st.push(b);
                st.push(a);
                break;
            }
        }
    }

    string ans = "";

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}

