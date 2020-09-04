#include <bits/stdc++.h>

using namespace std;

int v[] = {4,8,15,16,23,42};
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    queue<int> q[45];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        q[x].push(i);
    }
    
    int ans = 0;
    while(1) {
        int last = -1;
        bool flag = 1;
        for (int i = 0; i < 6; ++i) {
            
            while(!q[v[i]].empty() and q[v[i]].front() < last)  q[v[i]].pop();
            if(q[v[i]].empty()) {
                flag = 0;
                break;
            }
            int pos = q[v[i]].front();
            q[v[i]].pop();
            flag &= pos > last;
            last = pos;
        }
        if(!flag) break;
        ans += 6;
    }
    cout << n - ans << "\n";
    return 0;
}

