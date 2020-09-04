#include <bits/stdc++.h>

using namespace std;

int n,m,x;
long long a[2010];
long long b[2010];
long long vmx[2010*2010];
vector<pair<long long, long long> > da,db;

int bs(int id) {
    int a = -1;
    int b = db.size();

    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(db[mid].first * da[id].first > x) b = mid;
        else a = mid;
    }

    return b;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)
        scanf("%lld", a + i);

    for (int i = 0; i < m; ++i)
        scanf("%lld", b + i);

    scanf("%d", &x);

    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    for (int i = 1; i < m; ++i)
        b[i] += b[i - 1];
        
     
    for (int i = 0; i < n; ++i) 
        for (int j = i; j < n; ++j) {
            long long s = a[j] - a[i - 1];
            if(s <= x) da.push_back({s, j - i + 1});
        }

    for (int i = 0; i < m; ++i)
        for (int j = i; j < m; ++j) {
            long long s = b[j] - b[i - 1];
            if(s <= x) db.push_back({s, j - i + 1});
        }

    sort(da.begin(), da.end());
    sort(db.begin(), db.end());
    
    long long mx = 0;
    for (int i = 0; i < (int)db.size(); ++i) {
        mx = max(mx, db[i].second);
        vmx[i] = mx;
    }

    long long ans = 0;
    
    for (int i = 0; i < (int)da.size(); ++i) {
        int pos = bs(i);
        pos--;
        long long cur = vmx[pos];
        ans = max(ans, (long long)cur * da[i].second);
    }

    printf("%lld\n", ans);
    return 0;
}

