#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> > v(n);
    
    if(n <= 3) return puts("YES"),0;
    for (auto &p: v)
        cin >> p.first >> p.second;
    

    auto get = [] (int x, int y) {
        return make_pair(x,y);
    };

    auto slope = [&] (auto p1, auto p2) -> pair<int,int> {
        int num = p2.second - p1.second;
        int den = p2.first - p1.first;
        int g = __gcd(num, den);
        return get(num / g, den / g);
    };
    
    
    auto check = [&] (int id) -> bool {
        
        set<pair<int,int> > st;
        map<pair<int,int>, int> mp;

        for (int i = 0; i < n; ++i) {
            if(id == i) continue;
            st.insert(v[i]);
            mp[slope(v[id], v[i])]++;
        }
        int mx = -1;
        pair<int,int> cur = {-1, -1};

        for (auto p: mp) {
            if(p.second > mx) {
                mx = p.second;
                cur = p.first;
            }
        }

        for (int i = 0; i < n; ++i) {
            if(id == i) continue;
            if(slope(v[id], v[i]) == cur) {
                st.erase(v[i]);
            }
        }

        if(st.size() <= 1) return 1;

        set<pair<int,int> > st2;
        auto ini = *st.begin();
        st.erase(ini);

        for (auto p: st) {
            st2.insert(slope(p, ini));
        }   
        return st2.size() <= 1;
    };

    sort(v.begin(), v.end());

    bool flag = 0;
    for (int i = 0; i < min(5, (int)v.size()); ++i) {
        flag |= check(i);
    }
    
    cout << (flag ? "YES": "NO") << "\n";
    return 0;
}

