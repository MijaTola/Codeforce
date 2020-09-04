#include <bits/stdc++.h>

using namespace std;

int n,k;
int v[400010];

struct segmentTree {
    const int NEUTRO = 0;
    long long st[400010];
    int n;
   
    void update(int pos, long long value){
        for (st[pos += n] += value; pos > 1; pos >>= 1)
            st[pos >> 1] = st[pos] + st[pos ^ 1]; 
    }

    // interval[l,r)
    long long query(int l,int r){
        long long ans = NEUTRO;
        r++;
        for (l += n,r += n;l < r;l >>= 1,r >>= 1){
            if(l & 1) ans += st[l++];
            if(r & 1) ans += st[--r];
        }
        return ans;
    }
};

segmentTree st[12];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    k++;
    for (int i = 1; i <= k; ++i)
        st[i].n = 100010;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k ; ++j) {
            if (j == 1) {
                st[j].update(v[i], 1);
                continue;
            }
            st[j].update(v[i], st[j - 1].query(0, v[i] - 1));
        }
    }
    cout << st[k].query(0, 100010) << "\n";
    return 0;
}
