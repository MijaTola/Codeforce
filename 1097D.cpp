#include <bits/stdc++.h>

using namespace std;

int k;
vector<pair<long long, int> > dv;
void factor(long long n) {
    for (long long i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            int c = 0;
            while(n % i == 0) {
                c++;
                n /= i;
            }
            dv.push_back({i, c});
        }
    }
    if(n >= 2) dv.push_back({n, 1});
    sort(dv.begin(), dv.end());
}

int main() {
    long long n;
    cin >> n >> k;

    long long ans = 1;

    for (int i = 0; i < (int)dv.size(); ++i) {
        
    }

    return 0;
}

