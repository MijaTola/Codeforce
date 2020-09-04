#include <bits/stdc++.h>

using namespace std;

int v[30][50010];

int main() {
    
    string s;
    cin >> s;
 

    bool flag = 0;;
    for (int i = 0; i <= (int)s.size() - 26; ++i) {
        set<char> st;
        int a = 0;
        for (int j = i; j < i + 26; ++j) {
            if(s[j] == '?') a++;
            else st.insert(s[j]);
        }

        if(st.size() == 26) {
            flag = 1;
            break;
        }

        if(st.size() + a == 26) {
            flag = 1;
            set<char> b;
            for (char a = 'A'; a <= 'Z'; ++a) {
                b.insert(a);
            }

            for (int j = i; j < i + 26; ++j)
                if(s[j] != '?') b.erase(s[j]);

            for (int j = i; j < i + 26; ++j)
                if(s[j] == '?') {
                    s[j] = *b.begin();
                    b.erase(*b.begin());
                }
            break;
        }
        
    }

    if(!flag) return cout << "-1\n", 0;

    for (int i = 0; i < (int)s.size(); ++i)
        if(s[i] == '?') s[i] = 'A';

    cout << s << "\n";
    return 0;
}

