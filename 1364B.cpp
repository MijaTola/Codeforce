#include <bits/stdc++.h>

using namespace std;

int v[100010];
int s[100010];
int main() {

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> v[i];

        for (int i = 1; i < n; ++i) 
            s[i] = abs(v[i] - v[i - 1]);

        for (int i = 1; i < n; ++i)
            s[i] += s[i - 1];
        
        int pos = 0;

        vector<int> ans;
        ans.push_back(v[0]);


        auto ver = [&] (int x, int y) {
            int sum = s[y];
            if(x > 0) sum -= s[x];
            int cur = abs(v[y] - v[x]);
            return cur >= sum;
        };
        
        while(pos < n - 1) {
            int a = pos + 1, b = n;
            while(b - a > 1) {
                int mid = (a + b) / 2;
                if(ver(pos, mid)) a = mid;
                else b = mid;
            }
            ans.push_back(v[a]);
            pos = a;
        }

        cout << ans.size() << "\n";
        for (int x: ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}

