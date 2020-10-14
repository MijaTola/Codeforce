#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> v;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        long long sum = 0;
        bool flag = 1, flag2 = 0;

        for (int i = 0; i < n; ++i) {
            sum += (v[i] - k);
            flag &= v[i] == k;
            flag2 |= v[i] == k;
        }
        
        if(flag) cout << "0\n";
        else if(sum == 0 or flag2) cout << "1\n";
        else cout << "2\n";

    }


    return 0;
}

