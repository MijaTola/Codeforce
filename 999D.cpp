#include <bits/stdc++.h>

using namespace std;

int n,m;
long long v[200010];
queue<int> b[200010],q;
int main() {

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    
    for (int i = 0; i < n; ++i) {
        int mod = v[i] % m;
        b[mod].push(i);
    }
    int pos = 0;
    long long ans = 0;
    for (int i = 0; i < m * 2; ++i) {
        while((int)b[pos].size() > n / m) {
            q.push(b[pos].front());
            b[pos].pop();
        }
        while((int)b[pos].size() < n / m and !q.empty()) {
            b[pos].push(q.front());
            ans += abs((v[q.front()] % m) - i);
            v[q.front()] += abs((v[q.front()] % m) - i);
            q.pop();
        }
        pos = (pos + 1) % m;
    }


    cout << ans << "\n";

    for (int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << "\n";
    
    return 0;
}

