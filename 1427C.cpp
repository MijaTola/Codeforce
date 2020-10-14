#include <bits/stdc++.h>

using namespace std;

int dp[100010];

bool can (tuple<int,int,int> a, tuple<int,int,int> b) {
    auto [t,x,y] = a;
    auto [t1,x1,y1] = b;
    long long dis = abs(x - x1) + abs(y - y1);
    return dis <= abs(t1 - t);
};
int main() {

    int m,n;
    cin >> m >> n;

    vector<tuple<int,int,int> > v;
    v.push_back({0, 1, 1});

    for (int i = 0; i < n; ++i) {
        int t,x,y;
        cin >> t >> x >> y;
        v.push_back({t,x,y});
    }



    sort(v.begin(), v.end());
    for (int i = n; i >= 0; i--) {
        for (int j = i + 1, k = 0; j <= n and k < 2000; ++j, k++) {
            if(can(v[i], v[j])) {
                dp[i] = max(dp[i] , dp[j] + 1);
            }
        }
    }

    cout << dp[0] << "\n";
    return 0;
}

