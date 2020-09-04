#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;

int main() {
    
    for (int i = 0; i < 3; ++i) {
        int x,y;
        cin >> x >> y;
        v.emplace_back(x,y);
    }

    sort(v.begin(), v.end());
    int ans = 3;
    do {
        auto a = v[0];
        auto b = v[1];
        auto c = v[2];

        if(a.first == b.first and b.first == c.first) 
            ans = min(ans, 1);

        if(a.second == b.second and b.second == c.second) 
            ans = min(ans, 1);

        if(a.first == b.first and 
                (c.second <= min(a.second, b.second) or c.second >= max(a.second, b.second))) 
            ans = min(ans, 2);

        if(a.second == b.second and
                (c.first <= min(a.first, b.first) or c.first >= max(a.first, b.first))) 
            ans = min(ans, 2);

    } while(next_permutation(v.begin(), v.end()));

    cout << ans << "\n";
    return 0;
}

