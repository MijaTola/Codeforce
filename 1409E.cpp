#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> dx,dy;
int dp[200010][3];

int f(int pos, int cur) {
    if(cur == 2) return 0;
    if(pos == (int)dx.size()) return 0;
    
    int &ans = dp[pos][cur];
    if(ans != -1) return ans;
    ans = 0;

    
    int p = upper_bound(dx.begin(), dx.end(), dx[pos] + k) - dx.begin();

    int sz = p - pos;
    ans = max(ans, f(p, cur + 1) + sz);
    ans = max(ans, f(pos + 1, cur));
    return ans;
}
int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> k;
    
        for (int i = 0; i < n + 3; ++i) 
            for (int j = 0; j < 3; ++j) 
                dp[i][j] = -1;
        
        dx.clear();
        dy.clear();
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            dx.push_back(x);
        }
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            dy.push_back(x);
        }
    

        sort(dx.begin(), dx.end());

        cout << f(0,0) << "\n";

    }
    return 0;
}

