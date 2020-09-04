#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(), v.end());
        int res = 0;
        do {
            a = v[0], b = v[1] , c = v[2];
            int ans = 0;
            if(a) ans++, a--;
            if(c) ans++, c--;
            if(b) ans++, b--;
            if(a and b) ans++, a--,b--;
            if(a and c) ans++, a--,c--;
            if(c and b) ans++, c--,b--;
            if(a and b and c) ans++;
            res = max(res, ans);
        } while(next_permutation(v.begin(), v.end()));
        cout << res << "\n";

    }
    return 0;
}

