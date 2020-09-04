#include <bits/stdc++.h>

using namespace std;

long long v[110];
long long cnt[110];
long long del[110];
long long n,m,x;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        memset(v, 0, sizeof v);
        memset(del, 0, sizeof del);
        for (int j = 0; j <= 100; ++j) {
            v[j] = cnt[j] * j;
            v[j] += v[j - 1];
        }
        
        for (int j = 100; j >= 0; j--)
            del[j] = cnt[j] + del[j + 1];
       
        int pos = 1;
        while(pos <= 100 and v[pos] + x <= m) pos++;
        
        int a = -1, b = cnt[pos] + 1;
        while(b - a > 1) {
            long long mid = (a + b) / 2;
            if(mid * (long long)pos + v[pos - 1] + x > m) b = mid;
            else a = mid;
        }
       
        cout <<  cnt[pos] - a +  del[pos + 1] << " ";
        cnt[x]++;
        del[x]++;
    }
    cout << "\n";
    
    return 0;
}

