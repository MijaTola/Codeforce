#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    long long t;
    cin >> t;

    while(t--) {
        long long n,m;
    
        cin >> n >> m;
        vector<pair<long long,long long> > v;
        vector<long long> ac;
        for (long long i = 0; i < m; ++i) {
            long long a,b;
            cin >> a >> b;
            v.push_back({a , b});
            ac.push_back(a);
        }
        
        
        sort(v.rbegin(), v.rend());
        sort(ac.rbegin(), ac.rend());

        for (long long i = 1; i < m; ++i) 
            ac[i] += ac[i - 1];
    
        long long ans = 0;

        for (long long i = 0; i < m; ++i) {
            long long a = -1, b = ac.size();

            while(b - a > 1) {
                long long mid = (a + b) / 2;
                if(v[mid].first > v[i].second) a = mid;
                else b = mid;
            }

            long long pos = min(a, n - 1);
            long long sum = 0;
            if(pos >= 0) sum = ac[pos];
            
            long long left = n - (pos + 1);

            if(pos >= i) {
                sum += left * v[i].second;
            } else {
                sum += (left - 1) * v[i].second;
                sum += v[i].first;
            }
            ans = max(ans, sum);
        }

        cout << ans << "\n";
    }
    return 0;
}

