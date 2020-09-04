#include <bits/stdc++.h>

using namespace std;

string s;
int sz;
stack <char> st;
int main() {
    cin >> s;
    sz = s.size();
    st.push(s[0]);
    int c = 0;
    for (int i = 1; i < sz; ++i) {
        if(!st.empty() and s[i] == st.top()) {
            c++;
            st.pop();
        } else st.push(s[i]);
    }

    puts((c & 1)?"Yes":"No");
    return 0;
}


