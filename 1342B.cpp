#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        set<int> st;

        for (auto c: s)
            st.insert(c);

        if((int)st.size() == 1) {
            cout << s << "\n";
            continue;
        }
        int cur = 1;
        for (int i = 0; i < 2 *(int) s.size(); ++i) {
            cout << cur;
            cur = 1 - cur;
        }
        cout << "\n";
    }

    return 0;
}

