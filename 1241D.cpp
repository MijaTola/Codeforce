#include <bits/stdc++.h>

using namespace std;

int v[300010];
int b[300010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        map<int, int> ini, fin;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            if(!ini.count(v[i])) ini[v[i]] = i, fin[v[i]] = i;
            else fin[v[i]] = i;
        }
        int last = -1;
        int mx = 0;
        int c = 0;
        for (auto p: ini) {
            if(p.second > last) c++;
            else {
                mx = max(mx, c);
                c = 1;
            }
            last = fin[p.first];
        }
        mx = max(mx, c);
        cout << ini.size() - mx << "\n";
    }

    return 0;
}

