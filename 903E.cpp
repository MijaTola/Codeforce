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
        return (a * b)%p;
        T ans = 0;
        a %= p;
        while(b) {
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
        return ((h1[j] - mul(h1[i - 1], vpow[sz] % p)) + p) % p;
    }
};

int main() {
    
    int n,k;
    cin >> n >> k;

    vector<vector<int> > v;
    vector<string> ss;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        vector<int> b;
        for (int x: s)
            b.push_back(x - 'a');
        v.push_back(b);
        ss.push_back(s);
    }

    map<long long, int> mp;
    map<long long, tuple<int,int,int> > mp2;
    Hash<long long, 5010> h(33, INT_MAX);
    auto f = [&] (vector<int> &s, int y) {
        for (int i = 0; i < k; ++i) {
            for (int j = i + 1; j < k; ++j) {
                swap(s[i], s[j]);
                h.build(s);
                auto x = h.getH(0, s.size() - 1);
                mp[x]++;
                mp2[x] = {y, i, j};
                swap(s[i], s[j]);
            }
        }
    };

    for (int i = 0; i < n; ++i) 
        f(v[i], i);
    
    for (auto x: mp) {
        if(x.second == n) {
            auto tp = mp2[x.first];
            int p, i, j;
            tie(p, i, j) = tp;
            string ans = ss[p];
            swap(ans[i], ans[j]);
            cout << ans << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}

