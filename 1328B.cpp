#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t;
    cin >> t;

    while(t--) {
        
        int n,k;
        cin >> n >> k;

        long long cur = 0;
        bool flag = 1;
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            //tomo un 'a'
            long long m = n - i - 1;
            long long c = m * (m - 1) / 2;
            if(!flag) c = m;

            if(cur + c >= k) cout << "a";
            else {
                cout << "b";
                cnt++;
                flag = 0;
                cur += c;
            }
        }
        
        if(cnt == 2) cout << "a\n";
        else cout << "b\n";
    }

    return 0;
}

