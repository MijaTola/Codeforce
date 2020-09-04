#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int> > v;
int a[60010];
int b[60010];

bool ver(double k) {
    double l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        double d = abs(v[i].first - k);
        double t = d / v[i].second;
        if(v[i].first < k) {
            l = max(l, t);
        } else {
            r = max(r, t);
        }
    }
    return l <= r;
}
int main() {
    
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    
    for (int i = 0; i < n; ++i)
        scanf("%d", b + i);

    for (int i = 0; i < n; ++i)
        v.push_back({a[i], b[i]});


    double a = 0, b = 1e10;

    for (int i = 0; i < 100; ++i) {
        double mid = (a + b) / 2;
        if(ver(mid)) a = mid;
        else b = mid;
    }

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        double d = abs(v[i].first - b);
        double t = d / v[i].second;
        ans = max(ans, t);
    }
    cout.precision(14);
    cout << fixed << ans << "\n"; 
    return 0;
}

