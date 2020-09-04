#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,int> > v;
int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.emplace_back(x,y);
    }

    int a = 0, b = 1e9;

    auto check = [] (int ini) {
        int cur = ini;
        for (int i = 0; i < n; ++i) {
            cout << cur << " " << v[i].second << " lel\n";
            if(v[i].second == 1) {
                if(cur < 1900) return 0;
                cur += v[i].first;
            } else {
                if(cur >= 1900) return 0;
                cur += v[i].first;
            }
        }
        cout << cur << " xd\n";
        return 1;
    };

    cout << check(1901) << " gg\n";
    return 0;

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(check(mid)) a = mid;
        else b = mid;
    }

    cout << a << "\n";
    return 0;
}

