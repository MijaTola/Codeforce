#include <bits/stdc++.h>

using namespace std;

vector<int> v[200010];
map<int,vector<pair<int,int > > > mp;
int main(){
    int k; cin >> k;   

    for (int i = 0; i < k; ++i) {
        int n; cin >> n;
        int s = 0;
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            s += x;
            v[i].push_back(x);
        }
        set<int> st;
        for (int j = 0;j < n; ++j) {
            int s2 = s - v[i][j];
            if(st.count(s2)) continue;
            st.insert(s2);
            mp[s2].push_back({i,j});
        }
    }
    for (pair<int,vector<pair<int,int > > > p: mp) {
        if(p.second.size() >= 2) {
            cout << "YES\n";
            cout << p.second[0].first + 1<< " " << p.second[0].second + 1<< "\n";
            cout << p.second[1].first + 1<< " " << p.second[1].second + 1 << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}

