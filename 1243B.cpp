#include <bits/stdc++.h>

using namespace std;

int t,n;
string a,b;

void swap2(int i, int j) {
    swap(a[i], b[j]);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        
        if(a == b) {
            cout << "Yes\n1 1\n";
            return 0;
        }
        vector<pair<int,int> > ans;

        for (int i = 0; i < n; ++i) {
            if(a[i] == b[i]) continue;   
            int p = i + 1;
        
            while(a[p] != a[i] and p < n) p++;
            if(p < n) {
                swap2(p, i);
                ans.push_back({p,i});
                continue;
            }
            p = i;
            while(b[p] != a[i] and p < n) p++;
            if(p == n) goto noans;
            swap2(i + 1, p);
            ans.push_back({i + 1, p});
            swap2(i + 1, i);
            ans.push_back({i + 1, i});
        }
        
        if((int)ans.size() > 2 * n) goto noans;
        cout << "Yes\n";
        cout << ans.size() << "\n";

        for (auto p: ans)
            cout << p.first + 1 << " " << p.second + 1 << "\n";
        continue;

        noans:
        cout << "No\n";

    }
    return 0;
}

