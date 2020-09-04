#include <bits/stdc++.h>

using namespace std;

int n,r;

vector<pair<int,int> > v, b;
int main() {
    cin >> n >> r;
    
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
        if(y < 0) v.push_back({y,x});
    }
    
    sort(v.begin(), v.end());
    sort(b.rbegin(), b.rend());
    bool flag = 1;
    while(flag) {
        int pos = 0;
        flag = 0;
        while(v[pos].first > r) pos--;
        for (int i = 0; i <= pos; ++i) {
            if(v[i].second >=  0) {
                flag = 1;
                r += v[i].second;
                v[i].second = 0;
            }
        }
    }
    
    for (auto p: v) {
        if(r >= p.second) r += p.first;
        else return cout << "NO\n",0;
    }
    
    cout << "YES\n";
    return 0;
}

