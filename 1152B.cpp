#include <bits/stdc++.h>

using namespace std;

vector<long long> tpow;
set<long long> s;
map<long long, int> mp;
int main() {
    
    long long p = 0;
    while(p <= 31) {
        tpow.push_back((1LL << p) - 1);
        s.insert((1LL << p) - 1);
        mp[(1LL << p) - 1] = p;
        p++;
    }

    int x;
    cin >> x;
    int c = 0;
    vector<int> ans;
    int flag = 0;
    while(!s.count(x)) {
        if(!flag) {
            bool can = 0;
            int to = 0;
            for (int i = 30; i >= 0; i--) {
                if(x & (1 << i)) {
                    can = 1;
                    to |= (1 << i);
                } else {
                    if(!can) continue;
                    to |= (1 << i);
                }
            }
            x ^= to;
            ans.push_back(mp[to]);
        } else x++;
        c++;
        flag = !flag;
    }
    cout << c << "\n";
    if(c == 0) return 0;
    for (int p: ans)
        cout << p << " ";
    cout << "\n";
    return 0;
}

