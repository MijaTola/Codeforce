#include <bits/stdc++.h>

using namespace std;

int a[2000010];
int b[2000010];
int c[2000010];
long long ans[2000010];
int n,m,k, block_size;

bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b) {
    if (a.first.first / block_size != b.first.first / block_size)
        return a.first.first / block_size < b.first.first / block_size;
    return a.first.second < b.first.second;
}

int main() {
    
    cin >> n >> m >> k;

    block_size = sqrt(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    for (int i = 1; i <= n; ++i) {
        b[i] = a[i - 1];
        b[i] ^= b[i - 1];
    }

    vector<pair<pair<int,int> ,int> > q;
    for (int i = 0; i < m; ++i) {
        int x,y;
        cin >> x >> y;
        x--;
        q.push_back({{x,y}, i});
    }

    sort(q.begin(), q.end(), cmp);

    int l = 0, r = -1;
    long long a = 0;

    for (auto p: q) {
        while(r < p.first.second and r <= n) {
            a += c[b[++r] ^ k];
            c[b[r]]++;
        }

        while(l > p.first.first) {
            a += c[b[--l] ^ k];
            c[b[l]]++;
        }

        while(r > p.first.second) {
            c[b[r]]--;
            a -= c[b[r--] ^ k];
        }

        while(l < p.first.first) {
            c[b[l]]--;
            a -= c[b[l++] ^ k];
        }
        ans[p.second] = a;
    }

    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
    return 0;
}

