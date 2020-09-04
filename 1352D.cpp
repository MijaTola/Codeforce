#include <bits/stdc++.h>

using namespace std;

int v[1010];
int pre[1010];
int suf[1010];

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
            pre[i] = v[i];
            suf[i] = v[i];
        }
        
        for (int i = 1; i <= n; ++i) 
            pre[i] += pre[i - 1];

        for (int i = n; i >= 1; i--)
            suf[i] += suf[i + 1];
        
        int ans = 0, a = 0, b = 0, la = 0, lb = 0;
        int pa = 1, pb = n;
        bool flag = 1;
        while(pa <= pb) {
            int sum = 0;
            if(flag) {
                while(sum <= lb and pa <= pb) {
                    sum += v[pa++];
                }
                a += sum;
                la = sum;
            } else {
                while(sum <= la and pa <= pb) {
                    sum += v[pb--];
                }
                b += sum;
                lb = sum;
            }
            ans++;
            flag = !flag;
        }
        
        cout << ans << " " << a << " " << b << "\n";


    }
    return 0;
}

