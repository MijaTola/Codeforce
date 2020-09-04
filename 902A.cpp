#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;
int main(){
    int n,m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        int x,y;
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    int mx = 0;
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if(v[i].first <= pos) {
            mx = max(v[i].second, mx);
            pos = mx;
        }
    }
    
    if(pos >= m) puts("YES");
    else puts("NO");

    return 0;
}

