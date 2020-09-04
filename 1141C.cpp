#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n - 1);

    for (int &x: v)
        cin >> x;

    int ini = 1;
    int mn = 1;
    
    for (int x: v) {
        ini += x;
        mn = min(ini, mn);
    }

    int df = 1 - mn;

    vector<int> ans;

    ini = 1 + df;
    
    for (int x: v) {
        ans.push_back(ini);
        ini += x;
    }
    ans.push_back(ini);

    bool flag = 1;
    set<int> s;

    for (int x: ans) {
        flag &= x >= 1 and x <= n;
        s.insert(x);
    }
    
    if(!flag or (int)s.size() != n) return cout << "-1\n", 0;

    for (int x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}

