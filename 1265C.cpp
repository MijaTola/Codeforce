#include <bits/stdc++.h>

using namespace std;

int t,n,x;
int a1 = -1, a2 = -1, a3 = -1;
int main() {
    
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        map<int,int> mp;
        vector<pair<int,int> > v;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            mp[x]++;
        }
        
        if(n / 2 < 3 or (int)mp.size() < 3) {
            puts("0 0 0");
            continue;
        }
        for (auto p: mp)
            v.emplace_back(p.second, p.first);


        reverse(v.begin(), v.end());
        for (int i = 1; i < (int)v.size(); ++i)
            v[i].first += v[i - 1].first;
        
        
        while(v.back().first > n / 2) v.pop_back();
        
        a1 = -1, a2 = -1, a3 = -1;
        auto ver = [&v] (int k) {
            int g = v[k].first;
            for (int i = k + 1; i < (int)v.size(); ++i) {
                int s = v[i].first - v[k].first;
                int b = v.back().first - v[i].first;
                if(g and s and b and g < s and g < b) {
                    a1 = g, a2 = s, a3 = b;
                    return 1;
                }
            }
            return 0;
        };

        int a = -1, b = v.size() - 1;
        while(b - a > 1) {
            int mid = (a + b) / 2;
            if(ver(mid)) a = mid;
            else b = mid;
        }

        if(ver(a)) printf("%d %d %d\n", a1,a2,a3);
        else puts("0 0 0");
    }
    return 0;
}

