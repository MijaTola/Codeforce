#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    string s; 
    cin >> s;
    
    string cur = "";
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i){
        if(s[i] >= 'a' and s[i] <= 'z') 
            cur += s[i];
        else{ 
            set<char> st;
            for (int j = 0; j < (int)cur.size(); ++j)
                st.insert(cur[j]);
            ans = max(ans,(int)st.size());
            cur = "";
        }
    }
            set<char> st;
            for (int j = 0; j < (int)cur.size(); ++j)
                st.insert(cur[j]);
            ans = max(ans,(int)st.size());
    cout << ans << "\n";
    return 0;
}

