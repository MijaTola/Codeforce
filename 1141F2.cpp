#include <bits/stdc++.h>

using namespace std;

int n;
int v[1510];
vector<pair<int,int> > b;
map<long long, vector<pair<int,int> > > mp;

int main() {

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i) {
        long long cur = 0;
        for (int j = i; j >= 0; j--) {
            cur += v[j];
            mp[cur].emplace_back(j,i);
        }
    }
    
    vector<pair<int,int> > ans;

    for (auto p: mp) {
        vector<pair<int,int> > cur;
        sort(cur.begin(), cur.end());
        
        int last = -1;

        for (auto pp: p.second) {
            if(pp.first > last) {
                cur.push_back(pp);
                last = pp.second;
            }
        }

        if(cur.size() > ans.size())
            ans = cur;
    }


    cout << ans.size() << "\n";
    for (auto p: ans)
        cout << p.first + 1 << " " << p.second + 1<< "\n";
    

    return 0;
}


