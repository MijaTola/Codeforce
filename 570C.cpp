#include <bits/stdc++.h>

using namespace std;

int n,m;
string s;
set<pair<int,int> > st;

int main() {

    cin >> n >> m >> s;

    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        if(s[i] == '.') r = i;
        else {
            st.insert({l,r});
            l = i + 1;
            r = i + 1;
        }
    }
    st.insert({l,r});
    long long ans = 0;
    for (auto p: st) {
        cout << p.first << " " << p.second << " lel\n";
        ans += (p.second - p.first);
    }
    
    st.insert({10, 10});
    cout << ans << "\n";
    
    while(m--) {
        int x;
        char c;
        cin >> x >> c;
        x--;

        auto la = st.upper_bound(make_pair(x, 0));
        la--;
        auto p = *la;
        cout << p.first << " " << p.second << " gg\n";
        st.erase(p);
        ans -= (p.second - p.first);
    
        if(c == '.') {
            if(x + 1 == p.first) {
                st.insert({x, p.second});
                ans += p.second - p.first + 1;
            } else if(x - 1 == p.second) {
                st.insert({p.first, x});
                ans += p.second - p.first + 1;
            } else {
                st.insert({x, x});
            }
        } else {
            if(p.first <= x and x <= p.second) {
                cout << p.first << " " << x - 1 << " rango\n";
                if((x - 1) - p.first >= 1) {
                    ans += (x - 1 - p.first);
                    st.insert({p.first, x - 1});
                }
                if(p.second - (x + 1)>= 1) {
                    ans += (p.second - (x + 1));
                    st.insert({x + 1, p.second});
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

