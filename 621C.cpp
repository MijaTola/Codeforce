#include <bits/stdc++.h>

using namespace std;

int n,p;
int main() {

    cin >> n >> p;
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++i) {
        int l,r;
        cin >> l >> r;
        v.emplace_back(l, r);
    }
    
    long double sum = 0;
    
    auto get = [] (int l, int r) -> double {
        double a = r / p - (l - 1) / p;
        return (r - l + 1 - a) / (r - l + 1);
    };

    for (int i = 0; i < n; ++i) {
       sum += (1 - get(v[i].first, v[i].second) * get(v[(i + 1) % n].first, v[(i + 1) % n].second)) * 2000;
    }

    printf("%.10Lf\n", sum);
    return 0;
}

