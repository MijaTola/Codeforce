#include <bits/stdc++.h>

using namespace std;

map<string,int > mp,st;
int main() {
    
    int n,m;
    cin >> n >> m;
    deque<string> ans;
    for (int i = 0; i < n; ++i) {
        string s,t;
        cin >> s;
        st[s]++;
        t = s;
        reverse(t.begin(), t.end());
        if(mp[s] != 0) {
            ans.push_front(s);
            ans.push_back(t);
            st[s]--;
            st[t]--;
            mp[t]--;
        } else mp[t]++;
    }
    
   
    string cur = "";
    int mx = 0;
    for (auto x: st) {
        if(x.second) {
            string t = x.first;
            reverse(t.begin(), t.end());
            if(t != x.first) continue;
            if((int)x.first.size() > mx) {
                mx = x.first.size();
                cur = x.first;
            }
        }
    }
    string a = "";
    if(ans.size() == 0) {
        cout << cur.size() << "\n";
        cout << cur << "\n";
        return 0;
    }
    for (int i = 0; i < (int)ans.size(); ++i) {
        if(i == (int)ans.size() / 2) {
            a += cur;
        }
        a += ans[i];
    }
    cout << a.size() << "\n";
    cout << a << "\n";

    return 0;
}

