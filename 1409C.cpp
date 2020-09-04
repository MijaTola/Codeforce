#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int n,x,y;
        cin >> n >> x >> y;

        int mx = 1e9;
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int df = j - i;   
                int val = abs(y - x);
                int c = val / df;

                if(val % df == 0) {
                    int cur = n - j - 1;
                    int cur2 = i;
                    
                   
                    if(y + c * cur < mx and x - c * cur2 > 0) {
                        mx = y + c * cur;
                        ans.clear();
                        int ini = y + c * cur;
                        for (int k = 0; k < n; ++k) {
                            ans.push_back(ini);
                            ini -= c;
                        }
                    }
                }
            }
        }

        for (auto x: ans)
            cout << x << " ";
        cout << "\n";

    }
    return 0;
}

