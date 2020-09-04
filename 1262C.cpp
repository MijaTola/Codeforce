#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n,k;
        string s;
        cin >> n >> k >> s;
        int ini = 0;
        vector<pair<int,int> > ans;
        for (int p = 0; p < k - 1; p++, ini += 2) {
            bool found = 0;
            for (int i = ini; i < n - 1; ++i) {
                if(s[i] == ')' and s[i + 1] == '(') {
                    found = 1;
                    ans.emplace_back(ini, i + 1);
                    reverse(s.begin() + ini, s.begin() + i + 2);
                    break;
                }
            }
            if(found) continue;

            for (int i = ini; i < n - 1; ++i) {
                if(s[i] == '(' and s[i + 1] == ')') {
                    found = 1;
                    ans.emplace_back(i, i + 1);
                    ans.emplace_back(ini, i + 1);
                    reverse(s.begin() + i, s.begin() + i + 2);
                    reverse(s.begin() + ini, s.begin() + i + 2);
                    break;
                }
            }
        }

        int l = ini, r = n - 1;
        while(l < r) {
            if(s[l] == '(' and s[r] == ')') {
                l++,r--;
                continue;
            }
            if(s[l] == ')' and s[r] == '(') {
                reverse(s.begin() + l, s.begin() + r + 1);
                ans.emplace_back(l, r);
            }
            if(s[l] == s[r]) {
                if(s[l] == '(') {
                    for (int i = l + 1; i < r; ++i)
                        if(s[i] == ')') {
                            reverse(s.begin() + i, s.begin() + r + 1);
                            ans.emplace_back(i, r);
                            break;
                        }
                } else {
                    for (int i = l + 1; i < r; ++i)
                        if(s[i] == '(') {
                            reverse(s.begin() + l, s.begin() + i + 1);
                            ans.emplace_back(l, i);
                            break;
                        }
                }
            }
            l++, r--;
        }
        
        assert((int)ans.size() <= n);
        cout << ans.size() << "\n";
        for (auto p: ans)
            cout << p.first + 1 << " " << p.second + 1<< "\n";
    }
    return 0;
}

