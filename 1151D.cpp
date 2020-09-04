#include <bits/stdc++.h>

using namespace std;

//a * (j - 1) + b * (n - j)
//a * j - a + b * n - b * j
//a * j - b * j - a + b * n
//j * (a - b) - (a - b * n)
//
int n;
bool cmp(pair<long long, long long > a, pair<long long, long long> b) {
    return a.first - a.second  > b.first - b.second ;
}

vector<pair<long long, long long> > v;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    sort(v.begin(), v.end(), cmp);
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += v[i].first * i + v[i].second * (n - i - 1);
    }
    
    cout << ans << "\n";

    return 0;
}

