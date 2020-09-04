#include <bits/stdc++.h>

using namespace std;

int main() {

    ios::sync_with_stdio(false); cin.tie(0); 
    int n,m;
    cin >> n;
    queue<int> a,b;

    long long da = 0, db = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push(x);
        da += x;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        b.push(x);
        db += x;
    }
 
    if(da != db) return cout << "-1\n", 0;

    vector<long long> ans;

    int cnt = 0;
    for (int i = 0; i < n + m and !a.empty() and !b.empty(); ++i) {
        if(da < db) {
            da += a.front();
            a.pop();
        }  else if(da > db) {
            db += b.front();
            b.pop();
        } else {
            ans.push_back(da);
            da = a.front(), db = b.front();
            a.pop();
            b.pop();
        }
        cnt++;
        assert(cnt <= 1e8);
    }
    
    cout << ans.size() << "\n";
    return 0;
}
