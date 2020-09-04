#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    auto is = [] (auto x) {
        return x == 'a' or x == 'e' or x == 'i' or x == 'o' or x == 'u';
    };

    vector<pair<int, string> > v;
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        string s = "";
        for (auto c: x) 
            if(is(c)) s += c;
        reverse(s.begin(), s.end());
        v.emplace_back(s.size(), s);
    }

    vector<string> no;
    vector<pair<string, string> > y;
    
    int pos = 0;

    while(pos < n) {
        if(pos + 1 < n and (int)v[pos].second.size() == (int)v[pos + 1].second.size()
                and v[pos].second[0] == v[pos + 1].second[0]) {
            y.emplace_back(v[pos].second, v[pos + 1].second);
            pos += 2;
        } else no.push_back(v[pos++].second);
    }
    
    vector< pair< pair<string,string>, pair<string, string> > > ans;

    while(y.size() and no.size() >= 2) {
        auto a = no.back();
        no.pop_back();
        auto b = no.back();
        no.pop_back();
        ans.push_back({y.back(), {a,b}});
        y.pop_back();
    }

    while(y.size() >= 2) {
        auto a = y.back();
        y.pop_back();
        auto b = y.back();
        y.pop_back();
        ans.emplace_back(a,b);
    }

    cout << ans.size() << "\n";

    for (auto p: ans) {
        cout << p.second.first << " " << p.first.first << "\n";
        cout << p.second.second << " " << p.first.second << "\n";
    }

    return 0;
}
