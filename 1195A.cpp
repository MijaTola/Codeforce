#include <bits/stdc++.h>

using namespace std;

int v[1010];
int main() {
    
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v[x]++;
    }
    priority_queue<int> q;
    for (int i = 0; i < 1010; ++i) {
        if(v[i]){
            q.push(v[i]);
        }
    }
    int lim = (n + 1) / 2;
    int ans = 0;
    while(lim) {
        int x = q.top();
        q.pop();
        if(x >= 2) {
            x -= 2;
            lim--;
            ans += 2;
            if(x) q.push(x);
        } else {
            x--;
            lim--;
            ans++;
            if(x) q.push(x);
        }
    }
    cout << ans << "\n";
    return 0;
}

