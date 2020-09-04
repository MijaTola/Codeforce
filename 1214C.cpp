#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    
    cin >> n >> s;
    
    int o = 0, c = 0;
    for (int i = 0; i < n; ++i)
        if( s[i] == '(') o++;
        else c++;
    
    if(c != o) return cout << "NO\n",0;
    
    stack<int> st;
    
    bool first = 1;
    int pos = -1;

    for (int i = 0; i < n; ++i) {
        if(s[i] == '(') st.push(i);
        else {
            if(st.empty()) {
                if(first) {
                    pos = i;
                    first = 0;
                } else return cout << "NO\n",0;
            } else st.pop();
        }
    }
    if(st.size() == 1 and pos != -1) return cout << "YES\n", 0;
    if(st.size() == 0 and pos != -1) return cout << "NO\n",0;
    if(st.size() == 0 and pos == -1) return cout << "YES\n",0;
    cout << "NO\n";
        
    return 0;
}

