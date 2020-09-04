#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    
    priority_queue<int> q,q2;
    for (int i = 0; i < a1; ++i) {
        q.push(k1);
        q2.push(-k1);
    }

    for (int i = 0; i < a2; ++i){
        q.push(k2);
        q2.push(-k2);
    }
    
    int dn = n;
    int mn = 0;
    while(dn-- and !q.empty()) {
        int u = q.top();
        q.pop();
        u--;
        if(!u) mn++;
        else q.push(u);
    }
    
    int mx = 0;
    dn = n;

    while(dn-- and !q2.empty()) {
        int u = -q2.top();
        q2.pop();
        u--;
        if(!u) mx++;
        else q2.push(-u);
    }
    
    cout << mn << " " << mx << "\n";
    return 0;
}

