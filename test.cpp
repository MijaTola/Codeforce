#include <bits/stdc++.h>

using namespace std;

template <typename T, int MAX_N>
struct Hash {
    T p,x,n;    
    vector<T> h,h1,vpow;
    Hash(const vector<int> &v, T dx, T dp) {
        h.resize(MAX_N);
        h1.resize(MAX_N);
        vpow.resize(MAX_N);
        n = v.size();
        x = dx, p = dp;
        vpow[0] = 1;
        for (int i = 1; i <= n; ++i)
            vpow[i] = ((T) mul(vpow[i - 1], (T) x)) % p;

        T hash = 0;
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


    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;   
        vector<int> v;

        for (char x: s) 
            v.push_back(x - 'a' + 1);

        Hash<long long, 2000100> h(v, 33, INT_MAX);

        int a = -1, b = s.size() / 2;

        while(b - a > 1) {
            int mid = (a + b) / 2;
            long long h1 = h.getH(0, mid);
            long long h2 = h.getRh(s.size() - mid - 1, s.size() - 1);
            if(h1 == h2) a = mid;
            else b = mid;
        }

        int l = a;
        int r = s.size() - a - 1;

        int mx = 0;
        int dl = -1, dr = -1;
        for (int i = l + 1; i < r; ++i) {
            int mn = min(i - (l + 1), r - (i + 1));
            int ll = i - mn;
            int rr = i + mn;


            if(h.getH(ll, i - 1) == h.getRh(i + 1, rr)) {
                if(rr - ll + 1 > mx) {
                    mx = rr - ll + 1;
                    dl = ll, dr = rr;
                }
            }
            mn = min(i - (l + 1) + 1, r - (i + 1));
            ll = i - mn + 1;
            rr = i + mn;

            if(h.getH(ll, i) == h.getRh(i + 1, rr)) {
                if(rr - ll + 1 > mx) {
                    mx = rr - ll + 1;
                    dl = ll, dr = rr;
                }
            }

        }

        for (int i = 0; i <= l; ++i)
            cout << s[i];
        for (int i = dl; i <= dr; ++i)
            cout << s[i];
        for (int i = r; i < (int)s.size(); ++i)
            cout << s[i];
        cout << "\n";
    }
    return 0;
}

