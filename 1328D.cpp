#include <bits/stdc++.h>

using namespace std;

int v[200010];

int main() {

    int t;
    cin >> t;

    while(t--) {

        int n,x;
        cin >> n;

        set<int> s;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            s.insert(x);
            v[i] = x;
        }


        if(s.size() == 1) {
            cout << "1\n";
            for (int i = 0; i < n; ++i)
                cout << "1 ";
            cout << "\n";
            continue;
        }


        vector<pair<int,int> > b;
        int cnt = 0;
        int last = v[0];
        for (int i = 0; i < n; ++i) {
            if(last == v[i]) cnt++;
            else {
                b.emplace_back(cnt, last);
                cnt = 1;
            }
            last = v[i];
        }
        b.emplace_back(cnt, last);

        int mx = 2;
        vector<int> ans;
        if(b.size() % 2 == 0) {
            int c = 0;
            for (auto p: b) {
                for (int i = 0; i < (int)p.first; ++i) 
                    ans.push_back(c);
                c = 1 - c;
            }
        } else {
            if(b[0].second == b.back().second) {
                int c = 0;
                for (auto p: b) {
                    for (int i = 0; i < (int)p.first; ++i) 
                        ans.push_back(c);
                    c = 1 - c;
                }
            } else {
                bool flag = 1;
                int c = 0;
                for (int i = 0; i < (int)b.size() - 1; ++i) {
                    if(b[i].first >= 2 and flag) {
                        for (int j = 0; j < b[i].first - 1; ++j) {
                            ans.push_back(c);
                        }
                        ans.push_back(1 - c);
                        flag = 0;
                    } else {
                        for (int j = 0; j < b[i].first; ++j) {
                            ans.push_back(c);
                        }
                        c = 1 - c;
                    }
                }
                if(!flag) {
                    for (int i = 0; i < b.back().first; ++i)
                        ans.push_back(c);
                } else {
                    if(b.back().first >= 2) {
                        for (int j = 0; j < b.back().first - 1; ++j) {
                            ans.push_back(c);
                        }
                        ans.push_back(1 - c);
                    } else {
                        mx = 3;
                        for (int i = 0; i < b.back().first; ++i)
                            ans.push_back(2);
                    }
                }
            }
        }
        assert((int)ans.size() == n);
        cout << mx << "\n";
        for (auto x: ans) {
            assert(x >= 0 and x <= mx);
            cout << x + 1 << " ";
        }
        cout << "\n";

    }
    return 0;
}

