#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;

bool cmp(pair<int,int> a, pair<int,int> b) {
    int da = a.first - a.second;
    int db = b.first - b.second ;
    return da > db;
}
int main(){
    
    int n,m; cin >> n >> m;

    long long total = 0;
    for (int i = 0 ; i < n; ++i) {
        int a,b; cin >> a >>  b;
        v.push_back({a,b});
        total += a;
    }

    sort(v.begin(),v.end(),cmp);

    int p = 0;
    while(total > m and p < n) {
        total -= v[p].first;
        total += v[p].second;
        p++;
    }
    if(total <= m) cout << p << "\n";
    else cout << "-1\n";
    return 0;
}

