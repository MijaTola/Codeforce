#include <bits/stdc++.h>
using namespace std;

vector<long long> c[3010];

int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p, x;
        cin >> p >> x;
        c[p].push_back(x);
    }

    for (int i = 1; i <= m; i++) {
        sort(c[i].begin(), c[i].end());
    }

    long long res = 1e18;
    for (int lim = 0; lim < n; lim++) {
        long long add = 0;
        int per = c[1].size();
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int i = 2; i <= m; i++) {
            int r = (int) c[i].size() - lim;
            for (int j = 0; j < r; j++) {
                add += c[i][j];
                per++;
            }
            for (int j = max(0, r); j < (int)c[i].size(); j++) {
                pq.push(c[i][j]);
            }
        }
        while (!pq.empty() && per <= lim) {
            per++;
            add += pq.top();
            pq.pop();
        }
        if (per > lim) {
            res = min(res, add);
        }
    }
    cout << res << "\n";
    return 0;
}
