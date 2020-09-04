#include <bits/stdc++.h>

using namespace std;

long long v[200010];
long long ans[200010];
long long st[4 * 200010];
int n;

void update(int pos, int value) {
    for (st[pos += n] = value; pos > 1; pos >>= 1)
        st[pos >> 1] = st[pos] + st[pos ^ 1];
}

long long query(int l, int r) {
    long long ans = 0;
    r++;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) ans += st[l++];
        if(r & 1) ans += st[--r];
    }
    return ans;
}

int check(long long x) {
    int a = -1;
    int b = n;
    while(b - a > 1) {
        int mid = (a + b) / 2;
        if(query(0, mid) > x) b = mid;
        else a = mid;
    }
    return b;
}

int main() {
    
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        update(i, i + 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        int pos = check(v[i]);
        update(pos, 0);
        ans[i] = pos + 1;
    }
    
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}

