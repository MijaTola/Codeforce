#include <bits/stdc++.h>

using namespace std;

int v[70];

int main() {
    
    int t;
    cin >> t;
    while(t--) {
        memset(v, 0, sizeof v);
        long long n;
        int m;
        cin >> n >> m;
        long long sum = 0;
        for (int i = 0; i < m; ++i) {
            int x;
            cin >> x;
            sum += x;
            for (int j = 61; j >= 0; j--) 
                if(x & (1LL << j)) v[j]++;
        }

        if(sum < n) {
            cout << "-1\n";
            continue;
        }

        //1010

        int ans = 0;
        for (int i = 0; i < 61; ++i) {
            if(n & (1LL << i)) {
                if(v[i]) {
                    v[i]--;
                } else {
                    for (int k = i + 1; k < 61; ++k) {
                        if(v[k]) {
                            int dk = k;
                            while(dk != i) {
                                v[dk]--;
                                v[dk - 1] += 2;
                                dk--;
                                ans++;
                            }
                            v[dk]--;
                            break;
                        }
                    }
                }
            }
                
            v[i + 1] += v[i] / 2;
            v[i] -= v[i] / 2;

        }

        cout << ans << "\n";


    }
    return 0;
}

