#include <bits/stdc++.h>

using namespace std;

vector<int> v;

bool ver(int x) {
    while(x) {
        if(x % 10 == 7) return 1;
        x /= 10;
    }
    return 0;
}
int main(){
    for (int i = 0; i < 24; ++i) {
        for (int j = 0; j < 60; ++j) {
            if(ver(i) or ver(j)) {
                v.push_back(i * 60 + j);
            }
        }
    }
    
    int h,m,x;
    cin >> x >> h >> m;

    int cur = h * 60 + m;
    int ans = 1e9;
    for (int i = 0; i < (int)v.size(); ++i) {
        int dif = abs(cur - v[i]);
        if(v[i] > cur) dif = abs((cur + 24 * 60) - v[i]);
        if(dif % x == 0) ans = min(ans, dif / x);
    }
    cout << ans << "\n";
    return 0;
}

