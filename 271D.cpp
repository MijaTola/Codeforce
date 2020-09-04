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

        T  result = 0;
        a %= p;
        b %= p;
        while(b) {
            if(b & 0x1) {
                result += a;
                result %= p;
            }
            b >>= 1;
            if(a < p - a) {
                a <<= 1;
            } else {
                a -= (p - a);
            }
        }
        return result;
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


string s,da;
int k;
bool a[27];
long long v[2010];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s >> da >> k;
 
    for (int i = 0; i < (int)da.size(); ++i)
        a[i] = (da[i] == '0');
 
    for (int i = 0; i < (int)s.size(); ++i) 
        v[i] = a[s[i] - 'a'];
    
    vector<int> b;
    for (int i = 0; i < (int)s.size(); ++i) 
        b.push_back(s[i] - 'a' + 1);
 
    for (int i = 1; i < (int)s.size(); ++i)
        v[i] += v[i - 1];
 
    Hash<long long, 2010> h(b, 33, INT_MAX);
    Hash<long long, 2010>  h1(b, 33, 1e9+7);
 
    long long ans = 0;
    set<pair<long long, long long> > st;
    for (int i = 0; i < (int)s.size(); ++i) {
        for (int j = i; j < (int)s.size(); ++j) {
            int bad = v[j];
            if(i) bad -= v[i - 1];
            ans += (bad <= k 
                    and !st.count({h.getH(i,j), h1.getH(i,j)}));
            st.insert({h.getH(i,j), h1.getH(i,j)});
        }
    }
    cout << ans << "\n";
    return 0;
}

