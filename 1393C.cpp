#include <bits/stdc++.h>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        map<int,int> mp;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mp[x]++;
        }

        vector<int> v;

        for (auto [x,y]: mp) {
            v.push_back(y);
        }

        sort(v.rbegin(), v.rend());
        
        auto ver = [&] (int k) {
            vector<int> vis(n, 0);
            set<int> s;
            for (int i = 0; i < n; ++i)
                s.insert(i);

            for (int i = 0; i < (int)v.size(); ++i) {
                for (int j = 0, pos = *s.begin(); j < v[i] and pos < n; ++j, pos += (k + 1)) {
                    s.erase(pos);
                    vis[pos] = 1;
                }
            }

            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += vis[i];
            }
            return cnt >= n;
        };

        auto ver2 = [&] (int k) {
            reverse(v.begin(), v.end());
            vector<int> vis(n, 0);
            set<int> s;
            for (int i = 0; i < n; ++i)
                s.insert(i);

            for (int i = 0; i < (int)v.size(); ++i) {
                for (int j = 0, pos = *s.begin(); j < v[i] and pos < n; ++j, pos += (k + 1)) {
                    s.erase(pos);
                    vis[pos] = 1;
                }
            }

            reverse(v.begin(), v.end());
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                cnt += vis[i];
            }
            return cnt >= n;
        };
        
        int a = 0, b = n + 1;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid) or ver2(mid) ) a = mid;
            else b = mid;
        }

        cout << a << "\n";
    }
    return 0;
}

