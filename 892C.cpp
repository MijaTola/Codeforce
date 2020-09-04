#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> v(n),b;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if(v[i] == 1) b.push_back(i);
    }


    long long ans = 0;
    if((int)b.size() == 0) {

        int mx = INT_MAX;
        set<int> s;
        for (int i = 0; i < n; ++i) 
            for (int j = i + 1; j < n; ++j) {
                if(__gcd(v[i], v[j]) == 1) {
                    mx = min(mx, j - i - 1);
                } else s.insert(__gcd(v[i], v[j]));
            }
        
        if(mx != INT_MAX) ans = n + mx;
        else {
            if((int)s.size() == 1) ans = -1;
            else {
                for (int i = 0; i < n - 1; ++i) {
                    int g = __gcd(v[i], v[i + 1]);
                    for (int j = i + 2; j < n; ++j) {
                        if(__gcd(g, v[j]) == 1) 
                            mx = min(mx, j - i - 1);
                    }
                }
            }
            if(mx == INT_MAX) ans = -1;
            else ans = n + mx;
        }
        

    } else ans = n - b.size();
    
    cout << ans << "\n";
    return 0;
}
