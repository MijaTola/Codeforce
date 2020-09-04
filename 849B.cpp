#include <bits/stdc++.h>

using namespace std;

bool vis[1010];

int main() {

    int n;
    cin >> n;

    vector<int> v(n);

    for (int &x: v)
        cin >> x;
    
    auto slope = [] (double a, double b, double x, double y) {
        double xx = x - a;
        double yy = y - b;
        if(xx == 0) return -1e9;
        return yy / xx;
    };
    
    map<double, int> mp;

    for (int i = 0; i < n; ++i) {

        for (int j = i + 1; j < n; ++j) {
            double s = slope(i, v[i], j, v[j]);
            mp[s]++;
        }
    }

    int mx = 0;
    double ss = -1;

    for (auto p: mp) {
        if(p.second > mx) {
            mx = p.second;
            ss = p.first;
        }
    }
    
    vis[0] = 1;
    for (int i = 1; i < n; ++i) {
        double s = slope(0, v[0], i, v[i]);
        if(s == ss) vis[i] = 1;
    }

    int ini = -1;

    for (int i = 0; i < n; ++i) {
        if(!vis[i] and ini == -1) {
            ini = i;
        }
    }
    
    set<double> nos;
    nos.insert(ss);
    
    for (int i = ini + 1; i < n; ++i) {
        if(!vis[i]) {
            double s = slope(ini, v[ini], i, v[i]);
            nos.insert(s);
        }
    }
    if(mx and nos.size() == 1 and ini != -1) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

