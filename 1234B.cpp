#include <bits/stdc++.h>

using namespace std;

set<int> s;
queue<int> q;
int main() {
    
    int n,k;
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(s.count(x)) continue;
        s.insert(x);
        if((int)q.size() + 1 > k) {
            s.erase(q.front());
            q.pop();
        }
        q.push(x);
    }
    vector<int> a;
    while(!q.empty()) {
        a.push_back(q.front());
        q.pop();
    }
    cout << a.size() << "\n";
    for (int i = a.size() - 1; i >= 0; i--)
        cout << a[i] << " ";
    cout << "\n";
    return 0;
}

