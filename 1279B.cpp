#include <bits/stdc++.h>

using namespace std;

long long v[200010];
long long l[200010];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n,s;
        cin >> n >> s;

        for (int i = 0; i < n; ++i)
            cin >> v[i];
        
        l[0] = v[0];
        for (int i = 1; i < n; ++i) {
            l[i] = v[i];
            v[i] += v[i - 1];
        }


        auto ver = [&s] (int k, int cur) {
            long long val = v[k];
            if(k >= cur) val -= l[cur];
            return val <= s;
        };
        
        int ans = -1e9;
        int id = -1;
        for (int i = 0; i < n; ++i) {
            int a = -1, b = n;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(ver(mid, i)) a = mid;
                else b = mid;
            }
            
            if(a - 1 > ans) {
                ans = a - 1;
                id = i + 1;
            }
        }

        if(v[n - 1] <= s) id = 0;
        cout << id << "\n";
    }
    return 0;
}

