#include <bits/stdc++.h>

using namespace std;

template <typename T, int MAX_N>

struct Hash {

    T p,x,n;    
    vector<T> h,h1,vpow;

    Hash(T dx, T dp) {
        h.resize(MAX_N);
        h1.resize(MAX_N);
        vpow.resize(MAX_N);

        x = dx, p = dp;
        vpow[0] = 1;
        for (int i = 1; i < MAX_N; ++i)
            vpow[i] = ((T) mul(vpow[i - 1], (T) x)) % p;
    }

    void build(const vector<int> &v) {
        T hash = 0;
        n = v.size();

        for (int i = n - 1; i >= 0; i--) {
            hash = ((((T) mul(hash, x) + v[i]) % p) + p) % p;
            h[i] = hash % p;
        }
        hash = 0;
        for (int i = 0; i < n; ++i) {
            hash = ((((T) mul(hash, x) + v[i]) % p) + p) % p;
            h1[i] = hash % p;
        }
    }

    T mul(T a, T b) {
        return ((long long)a * b) % p;
        T ans = 0;
        a %= p;
        while(b > 0) {
            if(b & 1) ans = (ans + a) % p;
            a = (2 * a) % p;
            b >>= 1;
        }
        return ans % p;
    }

    T getH(int i, int j) {
        int sz = j - i + 1;
        return ((h[i] - mul(h[j + 1], vpow[sz]) % p) + p) % p;
    }

    T getRh(int i, int j) {
        int sz = j - i + 1;
        if(i - 1 < 0) return h1[j];
        return ((h1[j] - mul(h1[i - 1], vpow[sz] % p)) + p) % p;
    }
};

int ans[5010];
char s[5010];
int main() {
    Hash<int, 5010> h(33, 1e9 + 7);
    
    scanf("%s", s);
    vector<int> b;

    int sz = strlen(s);
    for (int i = 0; i < sz; ++i)
        b.push_back(s[i] - 'a' + 1);

    h.build(b);
    
    
    queue<pair<int,int> > q;

    for (int i = 0; i < sz; ++i)
        for (int j = i; j < sz; ++j) {
            if(h.getH(i,j) == h.getRh(i,j))
                q.push({i,j});
        }

    ans[1] = q.size();
    for (int i = 2, cur = sz - 1; cur > 0; cur /= 2, i++) {
        int n = q.size();
        for (int j = 0; j < n; ++j) {
            int l = q.front().first;
            int r = q.front().second;
            q.pop();
            int sz = r - l;
            int dl = r + 1;
            int dr = dl + sz;
            int h1 = h.getH(l,r);
            int h2 = h.getH(dl, dr);
            if(h1 == h2) q.push({l, dr});
            dl = r + 2;
            dr = dl + sz;
            h2 = h.getH(dl, dr);
            if(h1 == h2) q.push({l, dr});

        }
        ans[i] = q.size();
    }

    for (int i = 1; i <= sz; ++i)
        printf("%d ", ans[i]);
    puts("");
    return 0;
}

