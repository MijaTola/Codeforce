#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > e;
int cnt[100010];
int c[100010];

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int x,y;
        cin >> x >> y;
        e.push_back({x,y});
    }

    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    int cur = 0;

    for (auto p: e) {
        if(c[p.first] != c[p.second]) {
            cur++;
            cnt[p.first]++;
            cnt[p.second]++;
        }
    }

    for (int i = 1; i <= n; ++i) 
        if(cnt[i] >= cur) 
            return cout << "YES\n" << i << "\n",0;

    cout << "NO\n";

    

    return 0;
}

