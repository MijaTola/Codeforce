#include <bits/stdc++.h>

using namespace std;

const int big = 5000010;
bool prime[5000010];
vector<pair<long long,int> > f;
vector<long long> dv;

void get(long long n) {
    for (long long i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            dv.push_back((long long)i);
            dv.push_back((long long)n / i);
        }
    }
    sort(dv.begin(), dv.end());
}

void factors (long long n) {
    for (int i = 1; i < (int)dv.size(); ++i) {
        int c = 0;
        while(n % dv[i] == 0LL and dv[i] != 1) {
            //cout << n << " " << dv[i] << "lel\n";
            n /= dv[i];
            c++;
        }
        if(c) f.push_back(make_pair(dv[i],c));
    }
}

bool is(long long n) {

    for (long long i = 2; i * i <= n; ++i) 
        if(n % i == 0) return 0;
    return 1;
}

int main() {
    
    long long q;
    cin >> q;

    if(is(q)) return printf("1\n0\n"),0;
    get(q);
    factors(q);

    vector<long long> ff;

    for (int i = 0; i < (int) f.size(); ++i) {
        for (int j = 0; j < f[i].second; ++j) {
            ff.push_back(f[i].first);
        }
    }
    if(ff.size() >= 3) printf("1\n%lld\n",ff[0] * ff[1]);
    else puts("2");
    return 0;
}

