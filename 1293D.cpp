#include <bits/stdc++.h>

using namespace std;

long long xo,yo,ax,ay,bx,by,x,y,t;
vector<pair<long long, long long> > v;

int main() {

    cin >> xo >> yo >> ax >> ay >> bx >> by >> x >> y >> t;

    while(xo <= 3 * 1e16 + 10 and yo <= 3 * 1e16 + 10) {
        v.emplace_back(xo, yo);
        xo = ax * xo + bx;
        yo = ay * yo + by;
    }
    
    auto dis = [] (pair<long long, long long> p1, pair<long long, long long> p2) -> long long {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    };
    
    int ans = 0;

    for (int i = 0; i < (int)v.size(); ++i) {
        for (int j = i; j < (int)v.size(); ++j) {
            long long d = 0;
            for (int k = i + 1; k <= j; ++k) 
                d += dis(v[k], v[k - 1]);
            
            d += min(dis(v[i], make_pair(x,y)), dis(v[j], make_pair(x,y)));

            if(d <= t) ans = max(ans, j - i + 1);
        }
    }

    cout << ans << "\n";
    return 0;
}

