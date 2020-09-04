#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> v[100010];
int main() {
    cin >> n >> k;

    long long total = (n - 2) * 3 + 4;

    for (int i = 0; i < k; ++i) {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
    set<pair<int,int> > s;
    for (int i = 1; i <= n; ++i) {
        if(v[i].size() == 0) continue;
        s.insert({i,i});
        for (int id: v[i]) {
            for (int id2: v[i - 1]) {

                if(id < id2) s.insert({i, i - 1});
                else s.insert({i - 1, i});
            }

            for (int id2: v[i + 1]) {
                if(id < id2) s.insert({i, i + 1});
                else s.insert({i + 1, i});
            }
        }
    }
    cout <<total - (int)s.size() << "\n";
    return 0;
}

