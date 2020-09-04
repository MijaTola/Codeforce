#include <bits/stdc++.h>

using namespace std;

int v[1010];
int b[1010];
vector<pair<int,int> > p;
int main(){
    int n,m; cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x,y; cin >> x >> y;
        p.push_back({x,y});
    }
    bool flag = 0;
    for (int i = 1; i <= n; ++i) {
        v[i] = flag;
        flag = !flag;
    }
    flag = 1;
    for (int i = 1; i <= n; ++i) {
        b[i] = flag;
        flag = !flag;
    }

    int ans = 0;
    for (int i = 0; i < (int)p.size(); ++i) {
        int l = p[i].first;
        int r = p[i].second;
        int c = 0;
        for (int j = l; j <= r; ++j) 
            if(v[i]) c++;
        int total = r - l + 1;
        int k = total - c;
        ans += k * c;
    }

    int ans2 = 0;
    for (int i = 0; i < (int)p.size(); ++i) {
        int l = p[i].first;
        int r = p[i].second;
        int c = 0;
        for (int j = l; j <= r; ++j) 
            if(b[i]) c++;
        int total = r - l + 1;
        int k = total - c;
        ans2 += k * c;

    }

    if(ans > ans2) {
        for (int i = 1; i <= n; ++i) {
            cout << v[i];
        }
        cout << "\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << b[i];
        }
        cout << "\n";
    }
    return 0;
}

