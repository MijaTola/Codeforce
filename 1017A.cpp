#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > v;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) return a.second > b.second;
    return a.first < b.first ;
}

int main(){
    
    int n; cin >> n;

    for (int i = 0; i < n; ++i) {
        int s = 0;
        for (int j = 0; j < 4; ++j) {
            int x; cin >> x;
            s += x;
        }
        v.push_back({s,i});
    }

    sort(v.rbegin(),v.rend(),cmp);

    int p = 0;
    while(v[p].second != 0) p++;
    cout << p + 1<< "\n";
    return 0;
}

