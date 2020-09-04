#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;
vector<int> v;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        mp[x]++;
    }

    
    for (pair<int,int> p: mp) 
        v.push_back(p.second);

    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = v[0]; i >= 1; i--) {
        int ini = i;
        int pos = 0;
        int sum = 0;
        while(pos < (int)v.size()) {
            if(v[pos] >= ini and pos < (int)v.size()) {
                sum += ini;
                if(ini & 1) break;
                ini >>= 1;
                pos++;
            } else break;
        }
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
    return 0;
}

